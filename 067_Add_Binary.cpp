//
//  067_Add_Binary.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/23/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Solution2 {
    //more concise solution, use 'c' to store carry and sum
public:
    string addBinary(string a, string b){
        string s = "";
        
        int c = 0, i = (int)a.size() - 1, j = (int)b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1) {
            c += i >= 0 ? a[i --] - '0' : 0;
            c += j >= 0 ? b[j --] - '0' : 0;
            s = char(c % 2 + '0') + s;
            c /= 2;
        }
        return s;
    }
};


class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = (int)a.length();
        int len2 = (int)b.length();
        if(len1 < len2){
            return addBinary(b, a);
        }
        int c = 0;
        for(int i = 1; i <= len1; i++){
            if(i <= len2){
                int s = (a[len1 - i] - '0' + b[len2 - i] - '0' + c) % 2;
                c = (a[len1 - i] - '0' + b[len2 - i] - '0' + c) / 2;
                a[len1 - i] = s + '0';
            }else{
                int s = (a[len1 - i] - '0' + c) % 2;
                c = (a[len1 - i] - '0' + c) / 2;
                a[len1 - i] = s + '0';
                if(c == 0){
                    return a;
                }
            }
        }
        return (c)? "1" + a : a;
    }
};

/*
int main(){
    Solution ss;
    cout << ss.addBinary("11", "1") << endl;
}
*/