//
//  473_Matchsticks_to_Square.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/19/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution3 {
    //Based on Solution2, we can further check duplicates in DFS.
    //If buckets[i] is equal to previous bucket, skip it
public:
    bool makesquare(vector<int>& nums) {
        int sum = 0;
        int n = (int)nums.size();
        for(int num : nums){
            sum += num;
        }
        if(n < 4 || sum % 4){
            return false;
        }
        vector<int> buckets(4, 0);
        sort(nums.begin(), nums.end(), std::greater<int>());
        return DFS(nums, buckets, 0, sum / 4, n);
    }
    bool DFS(vector<int>& nums, vector<int>& buckets, int index, int target, int n){
        if(index >= n){
            return true;
        }
        for(int i = 0; i < 4; ++i){
            int dup = false;
            for(int j = 0; j < i; ++j){
                if(buckets[i] == buckets[j]){
                    dup = true;
                    break;
                }
            }
            if(dup){
                continue;
            }
            buckets[i] += nums[index];
            if(buckets[i] <= target && DFS(nums, buckets, index + 1, target, n)){
                return true;
            }
            buckets[i] -= nums[index];
        }
        return false;
    }
};



class Solution2 {
    //If we sort our input array first, the larger the first, we can execeed the target limit earlier and backtracking earlier
    //In practice, just add the sort step could make runtime from 1000+ ms --> 19ms
public:
    bool makesquare(vector<int>& nums) {
        int sum = 0;
        int n = (int)nums.size();
        for(int num : nums){
            sum += num;
        }
        if(n < 4 || sum % 4){
            return false;
        }
        vector<int> buckets(4, 0);
        sort(nums.begin(), nums.end(), std::greater<int>());    //important here
        return DFS(nums, buckets, 0, sum / 4, n);
    }
    bool DFS(vector<int>& nums, vector<int>& buckets, int index, int target, int n){
        if(index >= n){
            return true;
        }
        for(int i = 0; i < 4; ++i){
            if(i > 1 && buckets[i] == buckets[i - 1])
                continue;
            buckets[i] += nums[index];
            if(buckets[i] <= target && DFS(nums, buckets, index + 1, target, n)){
                return true;
            }
            buckets[i] -= nums[index];
        }
        return false;
    }
};


class Solution {
    //2-level DFS. Complicated
public:
    bool makesquare(vector<int>& nums) {
        int sum = 0;
        int n = (int)nums.size();
        for(int num : nums){
            sum += num;
        }
        if(n < 4 || sum % 4){
            return false;
        }
        sort(nums.begin(), nums.end());
        vector<int> left;
        vector<int> right;
        return partition(nums, left, 0, right, 0, 0, sum / 2, 1);
    }
    bool partition(vector<int>& nums, vector<int>& left, int sumLeft, vector<int>& right, int sumRight, int start, int target, int level){
        if(level == 1){
            if(sumLeft > target || sumRight > target){
                return false;
            }else if(start == (int)nums.size()){
                vector<int> LLeft, LRight, RLeft, RRight;
                return partition(left, LLeft, 0, LRight, 0, 0, target / 2, 2) && partition(right, RLeft, 0, RRight, 0, 0, target / 2, 2);
            }
        }else{
            if(sumLeft > target || sumRight > target){
                return false;
            }else if(start == (int)nums.size()){
                return true;
            }
        }
        if(right.empty() || nums[start] != right.back()){
            left.push_back(nums[start]);
            if(partition(nums, left, sumLeft + nums[start], right, sumRight, start + 1, target, level)){
                return true;
            }
            left.pop_back();
        }
        right.push_back(nums[start]);
        if(partition(nums, left, sumLeft, right, sumRight + nums[start], start + 1, target, level)){
            return true;
        }
        right.pop_back();
        return false;
    }
};


/*
int main(void){
    Solution ss;
    vector<int> nums{1,1,2,2,2};
    cout << ss.makesquare(nums);
}
*/
