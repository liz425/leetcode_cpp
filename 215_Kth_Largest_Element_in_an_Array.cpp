//
//  215_Kth_Largest_Element_in_an_Array.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/28/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand((unsigned int)time(NULL));
        return partition(nums, 0, (int)nums.size(), (int)nums.size() - k + 1);
    }
    int partition(vector<int>& nums, int start, int end, int k){
        if(start == end - 1)
            return nums[start];
        int index = rand() % (end - start) + start;
        int pivot = nums[index];
        //hide pivot to the right most
        swap(nums[index], nums[end - 1]);
        index = start;
        //do not iterate through the last item, which is the pivot
        for(int i = start; i < end - 1; ++i){
            //Must use '<=' rather than '<'
            //In the case that all nums are the same (e.g. {1,1,1,1,1})
            //if use '<', when loop finished, index == start, the range does not shrink
            //So once an item is equal to pivot, swap.
            if(nums[i] <= pivot){
                swap(nums[i], nums[index]);
                index++;
            }
        }
        if(k <= index - start){
            return partition(nums, start, index, k);
        }else{
            return partition(nums, index, end, k - (index - start));
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