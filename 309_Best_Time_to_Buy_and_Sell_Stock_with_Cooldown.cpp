//
//  309_Best_Time_to_Buy_and_Sell_Stock_with_Cooldown.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 3/19/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
    //Space O(n), Time: O(n)
public:
    // 0: buy, 1: sell, 2: hold, 3: cooldown
    int maxProfit(vector<int>& prices) {
        int k = (int)prices.size();
        if(k == 0)
            return 0;
        int profit[k][4];
        profit[0][0] = -1 * prices[0];
        profit[0][1] = 0;
        profit[0][2] = -1 * prices[0];
        profit[0][3] = 0;
        for(int i = 1; i < k; i++){
            profit[i][0] = profit[i - 1][3] - prices[i];
            profit[i][1] = max(profit[i - 1][0] + prices[i], profit[i - 1][2] + prices[i]);
            profit[i][2] = max(profit[i - 1][0], profit[i - 1][2]);
            profit[i][3] = max(profit[i - 1][1], profit[i - 1][3]);
        }
        return max(max(profit[k - 1][0], profit[k - 1][1]), max(profit[k - 1][2], profit[k - 1][3]));
    }
};

class Solution2 {
    //Space O(1), Time: O(n)
public:
    // 0: buy, 1: sell, 2: hold, 3: cooldown
    int maxProfit(vector<int>& prices) {
        int k = (int)prices.size();
        if(k == 0)
            return 0;
        int profit[4];
        int profit_tmp[4];
        profit[0] = -1 * prices[0];
        profit[1] = 0;
        profit[2] = -1 * prices[0];
        profit[3] = 0;
        for(int i = 1; i < k; i++){
            profit_tmp[0] = profit[3] - prices[i];
            profit_tmp[1] = max(profit[0] + prices[i], profit[2] + prices[i]);
            profit_tmp[2] = max(profit[0], profit[2]);
            profit_tmp[3] = max(profit[1], profit[3]);
            for(int j = 0; j < 4; j++){
                profit[j] = profit_tmp[j];
            }
        }
        return max(max(profit[0], profit[1]), max(profit[2], profit[3]));
    }
};