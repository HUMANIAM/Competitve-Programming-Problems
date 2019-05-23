#include "Orgnizing_Lottery.h"
class MergeSort{
private:
    vector<Element> elements;
public:
    MergeSort(vector<Element>& elements) : elements(elements)
    {}

    vector<Element> get_subList(int from, int to){
        vector<Element> sublist;
        for(int i = from; i <= to; i++)
            sublist.push_back(elements[i]);

        // add very biggest value
        sublist.push_back(Element(1<<30, 'b'));

        return sublist;
    }

    void put_in_order(vector<Element>& leftList, vector<Element>& rightList, int left){
        int leftSz = leftList.size();
        int rightSz = rightList.size();
        int i = 0, j = 0;

        while(i < leftSz - 1 || j < rightSz - 1){
            if(leftList[i].value < rightList[j].value)
                elements[left++] = leftList[i++];
            else
                elements[left++] = rightList[j++];
        }
    }

    void msmerge(int left, int centre, int right){
        //create temporary left and right array
        vector<Element> leftList = get_subList(left, centre);
        vector<Element> rightList = get_subList(centre + 1, right);

        //put left and right lists in the original list in order
        put_in_order(leftList, rightList, left);
    }

    void mergSort(int left, int right){
        if(left >= right)
            return;

        //divide the current list into 2 lists
        int centre = (left + right) / 2;
        mergSort(left, centre);
        mergSort(centre + 1, right);

        //merge the left and right lists
        msmerge(left, centre, right);
    }

    //driver function
    void mSort(){
        mergSort(0, elements.size() - 1);
    }

    //get sorted list
    vector<Element> get_sorted_list(){
        return elements;
    }
};


/**
labels >> point : p, start of segment : s, end of segment : e
*/
static vector<Element> make_label_list(vector<vector<int>>& segments, vector<int>& points){
    vector<Element> labeledElments;

    // append points
    for(const auto point : points)
        labeledElments.push_back(Element(point, 'p'));

    // append segments
    for(const auto segment : segments){
        labeledElments.push_back(Element(segment[0], 's'));
        labeledElments.push_back(Element(segment[1], 'e'));
    }

    return labeledElments;
}

/// set segments per point
static map<int, int> getMapofSegmentsPerPoint(vector<Element>& LabeledList){
    map<int, int> segmentsPerPoint;
    int starts = 0, ends = 0;
    for(const auto element : LabeledList)
        if(element.label == 'p'){
            segmentsPerPoint[element.value] = starts - ends;
        }else if(element.label == 's'){
            starts++;
        }else{
            ends++;
        }
    return segmentsPerPoint;
}

///get list of points per point
static vector<int> getListOfSegmentsPerPoint(map<int, int>& segmentsPerPointMap, vector<int>& points){
    vector<int> segmentsPerpointList(points.size(), 0);

    for(size_t i = 0; i < points.size(); i++)
        segmentsPerpointList[i] = segmentsPerPointMap[points[i]];

    return segmentsPerpointList;
}

/** organize lottery*/
vector<int> organize_lottery(vector<vector<int>>& segments, vector<int>& points){
    //make list of label elements contains points, start of segments, end of segments
    vector<Element> labeledList = make_label_list(segments, points);

    // sort the labeled list
    MergeSort ms = MergeSort(labeledList);
    ms.mSort();
    labeledList = ms.get_sorted_list();

    //get map of segments per point
    map<int, int> mapOfSegsPerPoint = getMapofSegmentsPerPoint(labeledList);

    //get list of segments per point
    vector<int> listOfSegsPerPoint = getListOfSegmentsPerPoint(mapOfSegsPerPoint, points);

    return listOfSegsPerPoint;
}
