//
//  247_Strobogrammatic_Number_II.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 1/7/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return helper(n, true);
    }
    vector<string> helper(int n, bool isOuterLoop){
        if(n == 0){
            return vector<string>{""};
        }else if(n == 1){
            return vector<string>{"0", "1", "8"};
        }else{
            vector<string> pre = helper(n - 2, false);
            vector<string> ret;
            int n = (int)pre.size();
            for(int i = 0; i < n; ++i){
                if(!isOuterLoop){
                    ret.push_back("0" + pre[i] + "0");
                }
                ret.push_back("1" + pre[i] + "1");
                ret.push_back("8" + pre[i] + "8");
                ret.push_back("6" + pre[i] + "9");
                ret.push_back("9" + pre[i] + "6");
            }
            return ret;
        }
    }
};
