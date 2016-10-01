//
//  202_Happy_Number.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/8/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> loop = {};
        while(n > 1){
            int sum = 0;
            while(n != 0){
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            if(loop.find(sum) != loop.end()){
                return false;
            }
            loop.insert(n = sum);
        }
        return (n == 1);
    }
};

/*
int main(void){
    Solution ss;
    cout << ss.isHappy(2) << endl;
}
*/