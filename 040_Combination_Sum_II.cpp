
//
//  040_Combination_Sum_II.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/14/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    //DFS, notice that each element from the set can be used only once in the same subset
public:
    void DFS(vector<vector<int>>& result, vector<int>& candidates, vector<int>& current, int index, int sum, int target){
        if(sum == target){
            result.push_back(current);
            return;
        }
        for(int i = index; i < (int)candidates.size(); ++i){
            if(sum + candidates[i] > target){
                break;
            }else if(i > index && candidates[i] == candidates[i - 1]){
                //avoid duplicated subsets
                continue;
            }
            current.push_back(candidates[i]);
            DFS(result, candidates, current, i + 1, sum + candidates[i], target);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> current;
        DFS(result, candidates, current, 0, 0, target);
        return result;
    }
};
