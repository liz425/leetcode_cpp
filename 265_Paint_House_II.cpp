//
//  265_Paint_House_II.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/31/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    //T = O(N*K), Space = O(K). Space could be further optimized to O(1)
    //Just store min and second min of the previous house
    //Avoid same color the current houst and previous house. If previous house with current color is min, use second min instead.
    //If we could modify the input costs function, then we can reduce Space to O(1).
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.empty() || costs[0].empty())
            return 0;
        int n = (int)costs.size();
        int k = (int)costs[0].size();
        vector<int> minCost(k, 0);
        priority_queue<int> maxHeap;
        int min = 0, secMin = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < k; ++j){
                if(minCost[j] == min){
                    minCost[j] = secMin + costs[i][j];
                }else{
                    minCost[j] = min + costs[i][j];
                }
                if(j < 2){
                    maxHeap.push(minCost[j]);
                }else if(minCost[j] < maxHeap.top()){
                    maxHeap.pop();
                    maxHeap.push(minCost[j]);
                }
            }
            secMin = maxHeap.top();
            maxHeap.pop();
            if(maxHeap.empty()){
                min = secMin;
            }else{
                min = maxHeap.top();
                maxHeap.pop();
            }
        }
        return min;
    }
};
