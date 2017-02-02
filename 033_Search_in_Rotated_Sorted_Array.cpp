//
//  033_Search_in_Rotated_Sorted_Array.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/18/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
    //A binary search template similar to STL.
    //Use [lo, hi) to indicate the search range, 'mid != hi' as the loop condition.
    //Also we can use lo < hi as the loop condition.
    //When loop ends, we only need to check 'mid', which is better than Solution1.
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        int lo = 0, hi = n;
        int mid = lo + (hi - lo) / 2;
        while(mid != hi && nums[mid] != target){    // we can also use 'lo < hi' as the loop condition
            //cout << lo << " " << mid << " " << hi << endl;
            if(nums[mid] >= nums[lo]){
                if(target >= nums[lo] && target < nums[mid]){
                    hi = mid;
                }else{
                    lo = mid + 1;
                }
            }else{
                if(target > nums[mid] && target <= nums[hi - 1]){
                    //Notice the last item is nums[hi - 1], NOT nums[hi]
                    lo = mid + 1;
                }else{
                    hi = mid;
                }
            }
            mid = lo + (hi - lo) / 2;
        }
        if(mid == hi){
            return -1;
        }else{
            return mid;
        }
    }
};



class Solution {
public:
    //Check Jiuzhang Algo., Basic Chap2 to get more details.
    int search(vector<int>& nums, int target) {
        if(nums.empty()){
            return -1;
        }
        int start = 0, end = (int)nums.size() - 1;
        while(start + 1 < end){
            int mid = start + (end - start) / 2;
            if(nums[mid] > nums[start]){
                if(target >= nums[start] && target <= nums[mid]){
                    end = mid;
                }else{
                    start = mid;
                }
            }else{
                if(target >= nums[mid] && target <= nums[end]){
                    start = mid;
                }else{
                    end = mid;
                }
            }
        }
        if(target == nums[start])
            return start;
        if(target == nums[end])
            return end;
        return -1;
    }
};
