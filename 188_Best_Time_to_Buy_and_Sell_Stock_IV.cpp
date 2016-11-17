//
//  188_Best_Time_to_Buy_and_Sell_Stock_IV.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/16/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k >= prices.size() / 2){
            int sum = 0;
            for(int i = 1; i < prices.size(); i++)
                sum += (prices[i] > prices[i - 1])? prices[i] - prices[i - 1] : 0;
            return sum;
        }
        vector<int> hold(k + 1, INT_MIN);
        vector<int> release(k + 1, 0);
        for(int price : prices){
            for(int i = 1; i <= k; i++){
                hold[i] = max(hold[i], release[i - 1] - price);
                release[i] = max(release[i], hold[i] + price);
            }
        }
        return release[k];
    }
};
