//
//  215_Kth_Largest_Element_in_an_Array.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/28/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution2 {
    //Use idea of quick select (part of quick sort)
    //T = O(n)
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand((unsigned int)time(NULL));
        return partition(nums, 0, (int)nums.size(), (int)nums.size() - k);
    }
    int partition(vector<int>& nums, int start, int end, int k){
        //k is 0-base
        if(start >= end - 1){
            return nums[start];
        }
        int index = rand() % (end - start) + start;
        int pivot = nums[index];
        //hide pivot to the right most
        swap(nums[index], nums[end - 1]);
        index = start;
        //do not iterate through the last item, which is the pivot
        for(int i = start; i < end - 1; ++i){
            //use either '<=' or '<' is ok
            //since after loop, index < end and index + 1 > start, the next partition will always shrink
            if(nums[i] <= pivot){
                swap(nums[i], nums[index]);
                index++;
            }
        }
        swap(nums[index], nums[end - 1]);
        if(index > k){
            return partition(nums, start, index, k);
        }else if(index < k){
            return partition(nums, index + 1, end, k);
        }else{
            return nums[index];
        }
    }
};



class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand((unsigned int)time(NULL));
        return partition(nums, 0, (int)nums.size(), (int)nums.size() - k + 1);
    }
    int partition(vector<int>& nums, int start, int end, int k){
        //return the kth smallest num
        if(start == end - 1)
            return nums[start];
        int pivotIndex = rand() % (end - start) + start;
        int pivot = nums[pivotIndex];
        int i = start - 1, j = end;
        //If item equals pivot, swap.
        while(1){
            while(nums[++i] < pivot);
            while(nums[--j] > pivot);
            if(i < j){
                swap(nums[i], nums[j]);
            }else
                break;
        }
        if(k <= i - start)
            return partition(nums, start, i, k);
        else
            return partition(nums, i, end, k - (i - start));
    }
};
