//
//  29_Divide_Two_Integers.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 6/15/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution3 {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0 || (dividend == INT_MIN && divisor == -1)){
            return INT_MAX;
        }
        int flag = ((dividend >= 0 && divisor > 0) || (dividend < 0 && divisor < 0)) ? 1 : 0;
        long dividend_l = abs(long(dividend));
        long divisor_l = abs(long(divisor));
        long bit = 1;
        while(dividend_l >= (divisor_l << 1)){
            divisor_l = divisor_l << 1;
            bit = bit << 1;
        }
        int result = 0;
        while(bit > 0){
            if(dividend_l >= divisor_l){
                dividend_l -= divisor_l;
                result += bit;
            }
            //cout << divisor_l << endl;
            divisor_l = divisor_l >> 1;
            bit = bit >> 1;
        }
        return flag? result : -result;
    }
};



class Solution2 {
    //Use long long to deal with 'abs(INT_MIN)'
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        int res = 0;
        while (dvd >= dvs) {
            long long temp = dvs, multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            res += multiple;
        }
        return sign == 1 ? res : -res;
    }
};


class Solution {
    //Using shift and convert it to binary number, since binary division result is either 0 or 1 in every iteration.
    //To deal with negtive number
public:
    int divide(int dividend, int divisor) {
        //consider overflow case
        if((divisor == 0) || (dividend == INT_MIN && divisor == -1)){
            return INT_MAX;
        }else if(dividend == 0){
            return 0;
        }
        
        unsigned int dividend_u = (dividend == INT_MIN)? ((unsigned int)(-(dividend + 1)) + 1) : ((unsigned int)(abs(dividend)));
        unsigned int divisor_u = (divisor == INT_MIN)? ((unsigned int)(-(divisor + 1)) + 1) : ((unsigned int)(abs(divisor)));
        bool flag = ((dividend > 0) == (divisor > 0));
        int result = 0;
        if(dividend_u < divisor_u){
            result = 0;
        }else{
            int len1 = int(log2(dividend_u)) + 1;
            int len2 = int(log2(divisor_u)) + 1;
            for(int i = len1 - len2; i >= 0; --i){
                if (dividend_u >= (divisor_u << i)){
                    result += (1 << i);
                    dividend_u -= (divisor_u << i);
                }
            }
        }
        return flag? result : -result;
    }
};

/*
int main(){
    Solution ss;
    int result = ss.divide(-1876, 13);
}
*/
