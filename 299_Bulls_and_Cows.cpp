//
//  299_Bulls_and_Cows.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/19/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <string>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int cnt[10] = {};
        int n = (int)secret.length();
        int a = 0, b = 0;
        for(int i = 0; i < n; i++){
            if(secret[i] == guess[i]){
                a++;
            }else{
                b = (cnt[secret[i] - '0'] < 0)? b + 1 : b;
                cnt[secret[i] - '0']++;
                
                b = (cnt[guess[i] - '0'] > 0)? b + 1 : b;
                cnt[guess[i] - '0']--;
            }
        }
        return to_string(a) + "A" + to_string(b) + "B";
    }
};