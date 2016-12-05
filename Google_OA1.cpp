//
//  Google_OA1.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/26/16.
//  Copyright © 2016 zl. All rights reserved.
//

//#include "inc.h"
#include <string>
#include <stdio.h>
#include <cmath>
#include <limits>
#include <algorithm>
#include <iostream>
using namespace std;

//replace two adjacent digits with the larger one， return min
int solution1(int X){
    string num = to_string(X);
    int n = (int)num.size();
    int result = INT_MAX;
    for(int i = 0; i < n - 1; ++i){
        char maxChar = char(max((int)num[i], (int)num[i + 1]));
        string remain = num.substr(0, i) + maxChar + num.substr(i + 2);
        result = min(result, stoi(remain));
    }
    return result;
}



//replace two adjacent digits with the round up average, return max
int solution2(int X){
    string num = to_string(X);
    int n = (int)num.size();
    int result = INT_MIN;
    for(int i = 0; i < n - 1; ++i){
        //round up
        int avrInt = (int)ceil((double(num[i] - '0') + double(num[i + 1] - '0')) / 2);
        char avrChar = char('0' + avrInt);
        cout << avrInt << endl;
        string remain = num.substr(0, i) + avrChar + num.substr(i + 2);
        result = max(result, stoi(remain));
    }
    return result;
}


//replace two adjacent digits group a single digit, return max
int solution3(int X){
    string num = to_string(X);
    int n = (int)num.size();
    int result = INT_MIN;
    for(int i = 0; i < n - 1; ++i){
        //round up
        if(num[i] == num[i + 1]){
            string remain = num.substr(0, i) + num.substr(i + 1);
            result = max(result, stoi(remain));
        }
    }
    return result;
}


//replace two adjacent digits group a single digit, return max
//with opptimization
int solution4(int X){
    string num = to_string(X);
    int n = (int)num.size();
    int result = INT_MIN;
    for(int i = 0; i < n - 1; ++i){
        //for continuous identical digits. only count the first two
        if((i == 0 || num[i] != num[i - 1]) && num[i] == num[i + 1]){
            string remain = num.substr(0, i) + num.substr(i + 1);
            result = max(result, stoi(remain));
        }
    }
    return result;
}


/*
int main(void){
    int X = 2147483647;
    cout << solution2(X) << endl;
}
*/
