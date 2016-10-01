//
//  012_Integer_to_Roman.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/6/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <cmath>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string ans;
        char rom[4][3] = {
            {'I', 'V', 'X'},
            {'X', 'L', 'C'},
            {'C', 'D', 'M'},
            {'M', 'M', 'M'}};
        
        for(int j = 3; j >= 0; j--){
            int denom = pow(10, j);
            if(int a = num / denom){
                if(a <= 3){
                    for(int i = 0; i < a; i++){
                        ans += rom[j][0];
                    }
                }else if(a == 4){
                    ans += rom[j][0];
                    ans += rom[j][1];
                }else if(a <= 8){
                    ans += rom[j][1];
                    for(int i = 0; i < a - 5; i++){
                        ans += rom[j][0];
                    }
                }else{
                    ans += rom[j][0];
                    ans += rom[j][2];
                }
                num = num - a * denom;
            }
        }
        return ans;
    }
};