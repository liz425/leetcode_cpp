//
//  300_Longest_Increasing_Subsequence.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 3/26/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution3{
    //Patience sorting, the code is exactly the same as Solution2, but the principle behind is different.
    //Time: O(nlogn)
public:
    int lengthOfLIS(vector<int>& nums){
        vector<int> result;
        for(int num : nums){
            if(result.size() == 0 || num > result.back())
                result.push_back(num);
            else
                *lower_bound(result.begin(), result.end(), num) = num;
        }
        return int(result.size());
    }
};


class Solution2{
    //Inspired by: http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
    //Time: O(nlogn)
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> result;
        for(int num : nums){
            if(result.size() == 0 || num > result.back())
                result.push_back(num);
            else
                *lower_bound(result.begin(), result.end(), num) = num;
        }
        return int(result.size());
    }
};


class Solution {
    //DP solution
    //Time complexity: O(n^2)
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        vector<int> numLens((int)nums.size());
        numLens[0] = 1;
        int maxLen = 1;
        for(int i = 1; i < nums.size(); i++){
            int lens = 1;
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    lens = max(lens, numLens[j] + 1);
                }
            }
            numLens[i] = lens;
            maxLen = max(maxLen, numLens[i]);
        }
        return maxLen;
    }
};