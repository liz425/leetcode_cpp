//
//  371_Sum_of_Two_Integers.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 7/7/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution3{
    //Recursive solution
public:
    int getSum(int a, int b){
        if(b){
            return getSum(a ^ b, (a & b) << 1);
        }
        return a;
    }
};


class Solution2 {
public:
    int getSum(int a, int b) {
        int sum = a;
        while (b != 0)
        {
            sum = a ^ b;        //calculate sum of a and b without thinking the carry
            b = (a & b) << 1;   //calculate the carry
            a = sum;            //add sum(without carry) and carry
        }
        return sum;
    }
};


class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int sum = 0;
        int shift = 0;
        while(shift <= 31){
            int bitA = a & 0x1;
            int bitB = b & 0x1;
            sum |= ((bitA ^ bitB ^ carry) << (shift++));
            carry = (bitA & bitB) | (bitA & carry) | (bitB & carry);
            a = a >> 1;
            b = b >> 1;
        }
        return sum;
    }
};


/*
int main(){
    Solution3 ss;
    cout << ss.getSum(1, -4) << endl;
}
*/