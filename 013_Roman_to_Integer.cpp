//
//  13_Roman_to_Integer.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/6/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
public:
    int romanToInt(string s) {
        if(s.empty()){
            return 0;
        }
        unordered_map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int len = (int)s.size();
        int sum = m[s[len - 1]];
        //IV, since we do not have IIV, once two identical char appears, it must be VII or II, then we should add them
        for(int i = 0; i <= len - 2; ++i){
            if(m[s[i]] >= m[s[i + 1]]){
                sum += m[s[i]];
            }else{
                sum -= m[s[i]];
            }
        }
        return sum;
    }
};



class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        int flag = 1;
        int prev = 0;
        int current = 0;
        for(int i = (int)s.length() - 1; i >= 0; i--){
            switch (s[i]){
                case 'I': current = 1; break;
                case 'V': current = 5; break;
                case 'X': current = 10; break;
                case 'L': current = 50; break;
                case 'C': current = 100; break;
                case 'D': current = 500; break;
                case 'M': current = 1000; break;
            }
            flag = (current > prev)? 1 : (current < prev)? -1 : flag;
            sum += flag * current;
            prev = current;
        }
        return sum;
    }
};
