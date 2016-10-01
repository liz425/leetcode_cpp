//
//  122_Best_Time_to_Buy_and_Sell_Stock_II.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/15/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i = 1; i < prices.size(); i++){
            profit += max(prices[i] - prices[i - 1], 0);
        }
        return profit;
    }
};
