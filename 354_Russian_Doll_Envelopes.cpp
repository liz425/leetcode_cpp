//
//  354_Russian_Doll_Envelopes.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/2/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
    //Use Lonest Increasing Subsequence to improve it!
    //T = O(n * logn)
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        auto comp = [](pair<int, int> a, pair<int, int> b){
            return (a.first == b.first)? a.second > b.second : a.first < b.first;
        };
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> LIS;
        for(auto envelop : envelopes){
            if(LIS.empty() || envelop.second > LIS.back()){
                LIS.push_back(envelop.second);
            }else{
                *(lower_bound(LIS.begin(), LIS.end(), envelop.second)) = envelop.second;
            }
        }
        return (int)LIS.size();
    }
};


class Solution {
    //Brutal force.
    //T = O(n^2), SLOW!!!!
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int size = (int)envelopes.size();
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(size, 1);
        int maxEvlp = 0;
        for(int i = 0; i < size; i++){
            for(int j = 0; j < i; j++){
                if(envelopes[j].first < envelopes[i].first && envelopes[j].second < envelopes[i].second){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxEvlp = max(maxEvlp, dp[i]);
        }
        return maxEvlp;
    }
};
