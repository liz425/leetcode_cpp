//
//  039_Combination_Sum.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/14/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    //DFS, notice that each element from the set can be used more than once in the same subset
    //Sort and remove duplicated elements in candidates
public:
    void DFS(vector<vector<int>>& result, vector<int>& candidates, vector<int>& current, int index, int sum, int target){
        if(sum == target){
            result.push_back(current);
            return;
        }
        for(int i = index; i < (int)candidates.size(); ++i){
            if(sum + candidates[i] > target){
                break;
            }
            current.push_back(candidates[i]);
            DFS(result, candidates, current, i, sum + candidates[i], target);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //Sort and remove duplicated elements in candidates
        sort(candidates.begin(), candidates.end());
        auto it = unique(candidates.begin(), candidates.end());
        vector<int> uniCandids(candidates.begin(), it);
        vector<vector<int>> result;
        vector<int> current;
        DFS(result, uniCandids, current, 0, 0, target);
        return result;
    }
};
