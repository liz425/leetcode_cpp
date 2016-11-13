//
//  128_Longest_Consecutive_Sequence.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 5/29/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution3 {
    // unordered_map implementation based on Solution2.
    // reduce times of hash inquiry, faster than solution2.
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> blocks;
        int maxLen = 0;
        for(int num : nums){
            if(blocks[num])     //already exist, maybe duplicated
                continue;
            int left = blocks[num - 1];
            int right = blocks[num + 1];
            blocks[num] = left + right + 1;
            blocks[num - left] = left + right + 1;
            blocks[num + right] = left + right + 1;
            maxLen = max(maxLen, left + right + 1);
        }
        return maxLen;
    }
};



class Solution2 {
    // unordered_map implementation, a little faster than first solution. Much more breif.
public:
    int longestConsecutive(vector<int>& nums) {
        int result = 0;
        unordered_map<int, int> m;
        for(auto& num : nums){
            if(m[num])  continue;
            m[num] = m[num + m[num + 1]] = m[num - m[num - 1]] = m[num - 1] + m[num + 1] + 1;
            result = max(result, m[num]);
        }
        return result;
    }
};

class Solution {
    // Set implementation, delete consecutive elements. Intuitive.
public:
    int longestConsecutive(vector<int>& nums) {
        int result = 0;
        set<int> s(nums.begin(), nums.end());
        while(!s.empty()){
            int val = *(s.begin());
            int cnt = 0;
            while(s.erase(val)){
                ++cnt;
                --val;
            }
            val += (cnt + 1);
            while(s.erase(val)){
                ++cnt;
                ++val;
            }
            result = max(result, cnt);
        }
        return result;
    }
};
