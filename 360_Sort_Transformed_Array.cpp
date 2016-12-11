//
//  360_Sort_Transformed_Array.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/10/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> result;
        int n = (int)nums.size();
        //if a == 0;
        if(a == 0){
            if(b == 0){
                result = vector<int>(n, c);
            }else if(b > 0){
                for(int i = 0; i < n; ++i){
                    result.push_back(b * nums[i] + c);
                }
            }else{
                for(int i = n - 1; i >= 0; --i){
                    result.push_back(b * nums[i] + c);
                }
            }
        }else{
            int i = 0, j = n - 1;
            double mid = -b / (2.0 * a);    //NOTE!!! should be 2.0, not 2!!!!
            while(i <= j){
                if(abs(nums[i] - mid) > abs(nums[j] - mid)){
                    result.push_back(a * nums[i] * nums[i] + b * nums[i] + c);
                    ++i;
                }else{
                    result.push_back(a * nums[j] * nums[j] + b * nums[j] + c);
                    --j;
                }
            }
            if(a > 0){
                reverse(result.begin(), result.end());
            }
        }
        return result;
    }
};
