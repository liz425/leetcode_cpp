//
//  391_Perfect_Rectangle.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/13/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
    //https://discuss.leetcode.com/topic/57339/c-o-nlogn-solution-using-multiset-and-o-n-solution-using-unordered_map
private:
    struct comp {
        bool operator () (const pair<int, int>& a, const pair<int, int>& b) { return a.second <= b.first; }
    };
    
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int area = 0, xmin = INT_MAX, ymin = INT_MAX, xmax = INT_MIN, ymax = INT_MIN;
        vector<vector<int>> verticalEdges;  // x, insertion/deletion event, ysmall, ylarge
        multiset<pair<int, int>, comp> s;   // for detecting overlaps
        
        // Calculate area, and configure verticalEdges
        for (auto rec : rectangles) {
            area += (rec[2] - rec[0]) * (rec[3] - rec[1]);
            xmin = min(xmin, rec[0]);
            ymin = min(ymin, rec[1]);
            xmax = max(xmax, rec[2]);
            ymax = max(ymax, rec[3]);
            //1: left vertical edge   0: right vertical edge
            verticalEdges.push_back({rec[0], 1, rec[1], rec[3]});
            verticalEdges.push_back({rec[2], 0, rec[1], rec[3]});
        }
        if (area != (xmax - xmin) * (ymax - ymin)) {
            return false;
        }
        
        // Check if any overlap exists
        sort(verticalEdges.begin(), verticalEdges.end());
        for (auto edge : verticalEdges) {
            auto it = s.find(make_pair(edge[2], edge[3]));
            if (edge[1] > 0) {                             // left edge, insertion event
                if (it != s.end()) {  // found an overlap
                    return false;
                }
                s.insert(make_pair(edge[2], edge[3]));
            } else {                                    // right edge, deletion event
                s.erase(it);
            }
        }
        return true;
    }
};



class Solution {
public:
    //Brutal force, TLE...
    bool isOverlap(vector<int>& recA, vector<int>& recB){
        return !(recA[0] >= recB[2] || recB[0] >= recA[2] || recA[1] >= recB[3] || recB[1] >= recA[3]);
    }
    int getArea(vector<int>& rec){
        return (rec[2] - rec[0]) * (rec[3] - rec[1]);
    }
    void maxRec(vector<int>& oldMax, vector<int>& newRec){
        oldMax[0] = min(oldMax[0], newRec[0]);
        oldMax[1] = min(oldMax[1], newRec[1]);
        oldMax[2] = max(oldMax[2], newRec[2]);
        oldMax[3] = max(oldMax[3], newRec[3]);
    }
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int size = (int)rectangles.size();
        vector<int> finalRec = {INT_MAX, INT_MAX, INT_MIN, INT_MIN};
        int sum = 0;
        for(int i = 0; i < size; ++i){
            maxRec(finalRec, rectangles[i]);
            //cout << finalRec[0] << finalRec[1] << finalRec[2] << finalRec[3] << endl;
            for(int j = 0; j < i; j++){
                if(isOverlap(rectangles[i], rectangles[j]))
                    return false;
            }
            sum += getArea(rectangles[i]);
            //cout << sum << endl;
        }
        //cout << getArea(finalRec) << endl;
        return sum == getArea(finalRec);
    }
};
