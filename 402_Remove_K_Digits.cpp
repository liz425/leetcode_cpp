//
//  402_Remove_K_Digits.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/12/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"



class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = k;
        deque<char> increase;
        int size = (int)num.size();
        for(int i = 0; i < size; ++i){
            while(!increase.empty() && n > 0 && num[i] < increase.back()){
                increase.pop_back();
                n--;
            }
            increase.push_back(num[i]);
        }
        string result = "";
        n = size - k;
        bool leadingZero = true;
        while(n > 0){
            if(increase.front() != '0' || !leadingZero){
                //remove leading zeros
                result += increase.front();
                leadingZero = false;
            }
            increase.pop_front();
            n--;
        }
        //in case result if empty
        if(result.empty())
            return "0";
        return result;
    }
};
