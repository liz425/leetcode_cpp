//
//  273_Integer_to_English_Words.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/19/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    vector<string> tens = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> ones = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
public:
    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        else
            return int2string(num).substr(1);
    }
    string int2string(int num){
        if(num >= 1000000000){
            return int2string(num / 1000000000) + " Billion" + int2string(num % 1000000000);
        }else if(num >= 1000000){
            return int2string(num / 1000000) + " Million" + int2string(num % 1000000);
        }else if(num >= 1000){
            return int2string(num / 1000) + " Thousand" + int2string(num % 1000);
        }else if(num >= 100){
            return int2string(num / 100) + " Hundred" + int2string(num % 100);
        }else if(num >= 20){
            return " " + tens[num / 10] + int2string(num % 10);
        }else if(num >= 1){
            return " " + ones[num];
        }else{
            return "";
        }
    }
};
