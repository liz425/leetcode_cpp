//
//  121_Best_Time_to_Buy_and_Sell_Stock.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 3/19/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX, max = INT_MIN;
        int n = (int)prices.size();
        if(n == 0)return 0;
        for(int i = 0 ; i < n; i++){
            if(prices[i] < min)
                min = prices[i];        //update the minimum found this till point
            if(max < prices[i] - min)
                max = prices[i]-min;    //calculate profit based on minimum found yet
        }
        return max;
    }
};


//int main(void){
//    Solution sol;
//    vector<int> ss = {2,3,4,8,7,1,4,9,4,2,7,9,2,2,2,9};
//    cout << sol.maxProfit(ss) << endl;
//}