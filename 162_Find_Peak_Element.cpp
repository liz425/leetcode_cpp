//
//  162_Find_Peak_Element.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 7/27/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.empty()) return 0;
        return helper(nums, 0, (int)nums.size() - 1);
    }
    int helper(vector<int>& nums, int low, int high){
        if(low == high){
            return low;
        }else{
            int mid_left = low + (high - low) / 2;
            int mid_right = mid_left + 1;
            if(nums[mid_left] < nums[mid_right]){
                low = mid_right;
            }else{
                high = mid_left;
            }
            return helper(nums, low ,high);
        }
    }
};

/*
int main(){
    Solution ss;
    vector<int> nums = {1,2,3,1};
    cout << ss.findPeakElement(nums) << endl;
}
*/
