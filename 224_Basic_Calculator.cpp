//
//  224_Basic_Calculator.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/20/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    int calculate(string s) {
        int sum = 0;
        int operand = 0;
        int myOperator = 1;
        stack<int> signs;
        signs.push(1);
        s += '+';   //for the sake of the last operand being added to sum
        for(char ch : s){
            if(ch == ' '){
                continue;
            }else if(ch >= '0' && ch <= '9'){
                operand = operand * 10 + int(ch - '0');
            }else{
                sum += operand * myOperator * signs.top();
                operand = 0;
                if(ch == '+'){
                    myOperator = 1;
                }else if(ch == '-'){
                    myOperator = -1;
                }else if(ch == '('){
                    signs.push(signs.top() * myOperator);
                    myOperator = 1;
                }else if(ch == ')'){
                    signs.pop();
                }else{
                    continue;
                }
            }
        }
        return sum;
    }
};
