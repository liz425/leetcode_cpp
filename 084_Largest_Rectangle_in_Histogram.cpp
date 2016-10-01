//
//  084_Largest_Rectangle_in_Histogram.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 6/16/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution2 {
    //Theoritically, this appoach has time complexity larger than O(n), but it runs fast than the fisrt solution indeed.
    //Run time: 16 ms
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = (int)heights.size();
        int Area = 0;
        vector<int> left(n,0);
        vector<int> right(n,0);
        for(int i = 1; i < n; ++i){
            int j = i - 1;
            while(j >= 0 && heights[i] <= heights[j]){
                j -= (left[j] + 1);
            }
            left[i] = i - j - 1;  //starts from i, how far the rectangle can go toward left
        }
        for(int i = n - 2; i >= 0; --i){
            int j = i + 1;
            while(j < n && heights[i] <= heights[j]){
                j += (right[j] + 1);
            }
            right[i] = j - i - 1; //starts from i, how far the rectangle can go toward right
        }
        for(int i = 0; i < n; ++i){
            Area = max(Area, heights[i] * (right[i] + 1 + left[i])); //Bottom: left[i]+right[i]+1
        }
        return Area;
    }
};


class Solution {
    //Time complexity: O(n), only put ascending elements in stack. Every element push and pop once.
    //Run time: 24ms
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        //add a sentinal to the end of the vector
        heights.push_back(0);
        int len = (int)heights.size();
        int area_max = 0;
        for(int i = 0; i < len; ++i){
            while(!stk.empty() && heights[stk.top()] > heights[i]){
                int height = heights[stk.top()];
                stk.pop();
                int left = (stk.empty())? -1 : stk.top();
                int area_new = height * (i - left - 1);
                area_max = max(area_max, area_new);
            }
            stk.push(i);
        }
        return area_max;
    }
};