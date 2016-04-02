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

class Solution2{
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for (int a : nums)
            if (ans.size() == 0 || a > ans.back()) ans.push_back(a);
            else *lower_bound(ans.begin(), ans.end(), a) = a;
        return (int)ans.size();
    }
};


class Solution {
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