//
//  324_Wiggle_Sort_II.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/1/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
    //Virtual indexing
    //O(n) time (average), O(1) space
public:
    void wiggleSort(vector<int>& nums) {
        int n = (int)nums.size();
        
        // Find a median.
        auto midPtr = nums.begin() + n / 2;
        nth_element(nums.begin(), midPtr, nums.end());
        int mid = *midPtr;
        
        // Index-rewiring.
        #define A(i) nums[(1+2*i) % (n|1)]
        
        // 3-way-partition-to-wiggly in O(n) time with O(1) space.
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (A(j) > mid){
                swap(A(i), A(j));
                i++;
                j++;
            }else if (A(j) < mid){
                swap(A(j), A(k));
                k--;
            }else{
                j++;
            }
        }
    }
};


class Solution {
    //Sort, T = O(n*logn), space = at least O(n) since we create a new vector. Depends on the sort algo.
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> buf = nums;
        sort(buf.begin(), buf.end());
        int n = (int)buf.size();
        int k = (n + 1) / 2;
        for(int i = 0; i < k; ++i){
            nums[(k - i - 1) * 2] = buf[i];
        }
        for(int i = n - 1; i >= k; --i){
            nums[(n - 1 - i) * 2 + 1] = buf[i];
        }
        return;
    }
};


