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
        int result = 0;
        unordered_map<int, int> m;
        for(auto& num : nums){
            if(m[num])  continue;
            int a = m[num - 1];
            int b = m[num + 1];
            int tmp;
            if(a == 0 && b == 0){
                tmp = m[num] = 1;
            }else if(a != 0 && b == 0){
                tmp = m[num] = m[num - a] = a + 1;
            }else if(a == 0 && b != 0){
                tmp = m[num] = m[num + b] = b + 1;
            }else{
                tmp = m[num] = m[num - a] = m[num + b] = a + b + 1;
            }
            result = max(result, tmp);
        }
        return result;
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