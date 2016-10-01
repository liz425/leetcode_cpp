//
//  391_Perfect_Rectangle.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/13/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

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
