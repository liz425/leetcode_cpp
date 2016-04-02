//
//  011_Container_With_Most_Water.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 3/24/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

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