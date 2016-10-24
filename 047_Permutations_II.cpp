//
//  047_Permutations_II.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/22/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    //we can't use swap to store the chosen element in the last (k-th) position as we do in 046_Permutation
    //Because we must keep nums sorted and skip identical elements to avoid duplication
    //If we swap elements in nums, the sorted order will be changed. Thus we need a new 'vector<int> candid' to store permutate
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());
        vector<bool> visited(n, false);
        vector<vector<int>> result;
        vector<int> candid;
        dfs(nums, visited, candid, result);
        return result;
    }
private:
    void dfs(vector<int>& nums, vector<bool>& visited, vector<int>& candid, vector<vector<int>>& result){
        if(candid.size() == nums.size()){
            result.push_back(candid);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(!visited[i] && (i == 0 || nums[i] != nums[i - 1] || visited[i - 1])){
                visited[i] = true;
                candid.push_back(nums[i]);
                dfs(nums, visited, candid, result);
                candid.pop_back();
                visited[i] = false;
            }
        }
    }
};
