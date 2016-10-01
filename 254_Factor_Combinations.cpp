//
//  254_Factor_Combinations.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/22/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> getFactors(int n) {
        vector<int> current;
        DFS(current, n, 2);
        return result;
    }
    void DFS(vector<int> current, int n, int start){
        //At any recursion level, current is always an monotonic increasing vector
        //When enter a new recursion, we will only add factor i >= start
        //We have two choices: add n as a factor, or call DFS to factorization n
        //Since i*i <= n, in next DFS call, next_start = current_i <= current_n/current_i = next_n
        //So, in current DFS call, n >= start, and we can directly add n to current and keep its monotonicity
        //except for the case when n initialized to 1, which can be excluded by check whether current is empty.
        for(int i = start; i*i <= n; ++i){
            if(n % i == 0){
                current.push_back(i);
                DFS(current, n / i, i);
                current.pop_back();
            }
        }
        if(!current.empty()){
            current.push_back(n);
            result.push_back(current);
            current.pop_back();
        }
        return;
    }
};
