//
//  091_Decode_Ways.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 8/27/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution {
public:
    int numDecodings(string s) {
        if(s.empty())
            return 0;
        vector<int> DP(s.size() + 1, 0);
        DP[0] = 1;
        for(int i = 1; i < DP.size(); ++i){
            if(s[i - 1] > '0')
                DP[i] = DP[i - 1];
            if(i >= 2 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] < '7')))
                DP[i] += DP[i - 2];
        }
        return DP[s.size()];
    }
};