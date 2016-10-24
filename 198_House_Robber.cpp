//
//  198_House_Robber.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/10/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
public:
    int rob(vector<int>& nums) {
        int dayBfrYstrd = 0;
        int yesterday = 0;
        for(int i = 0; i < nums.size(); ++i){
            int today = max(dayBfrYstrd + nums[i], yesterday);
            dayBfrYstrd = yesterday;
            yesterday = today;
        }
        return yesterday;
    }
};



class Solution {
public:
    int rob(vector<int>& nums) {
        //DP[n] = max(DP[n-2] + nums[n], DP[n-1])
        int DP[2] = {0, 0};
        for(int i = 0; i < nums.size(); i++){
            DP[(i+2)%2] = max(DP[i%2] + nums[i], DP[(i+1)%2]);
        }
        return DP[(nums.size()+1)%2];
    }
};
