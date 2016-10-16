//
//  011_Container_With_Most_Water.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 3/24/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution3 {
    //skip multiple vertical line if it's smaller than the previous border
public:
    int maxArea(vector<int>& height) {
        int maxA = 0;
        int i = 0, j = (int)height.size() - 1;
        while(i < j){
            maxA = max(maxA, min(height[i], height[j]) * (j - i));
            if(height[i] > height[j]){
                int r = j--;
                while(i < j && height[j] <= height[r]){
                    --j;
                }
            }else{
                int l = i++;
                while(i < j && height[i] <= height[l]){
                    ++i;
                }
            }
        }
        return maxA;
    }
};


class Solution2 {
public:
    //skip if it's decreasing
    int maxArea(vector<int>& height) {
        if(height.size() <= 1)
            return 0;
        int i = 0, j = (int)height.size() - 1;
        int maxWater = 0;
        while(i < j){
            maxWater = max(maxWater, min(height[i], height[j]) * (j - i));
            if(height[i] < height[j]){
                do{
                    i++;
                }while(i < j && height[i - 1] >= height[i]);
            }else{
                do{
                    j--;
                }while(i < j && height[j] <= height[j + 1]);
            }
        }
        return maxWater;
    }
};



class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = (int)height.size() - 1;
        int max_cur = Area(height, left, right);
        while(left < right){
            if(height[left] < height[right]){
                max_cur = max(Area(height, ++left, right), max_cur);
            }else{
                max_cur = max(Area(height, left, --right), max_cur);
            }
        }
        return max_cur;
    }
    int Area(vector<int>& height, int i, int j){
        return min(height[i], height[j]) * (j - i);
    }
};
