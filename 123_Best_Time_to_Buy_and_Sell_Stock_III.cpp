//
//  123_Best_Time_to_Buy_and_Sell_Stock_III.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/16/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold1 = INT_MIN, hold2 = INT_MIN;
        int release1 = 0, release2 = 0;
        for(auto price : prices){
            //in this order, it allows multi operation in one day, but still meet the requirement of selling before buy again
            hold1 = max(hold1, -price);
            release1 = max(release1, hold1 + price);
            hold2 = max(hold2, release1 - price);
            release2 = max(release2, hold2 + price);
            //cout << hold1 << " : " << release1 << " : " << hold2 << " : " << release2 << endl;
        }
        return release2;
    }
};
