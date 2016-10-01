//
//  165_Compare_Version_Numbers.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/27/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
using namespace std;


class Solution2 {
    //use string stream to easily read in a word / int
public:
    int compareVersion(string version1, string version2) {
        for(auto& w : version1) if (w == '.') w=' ';
        for(auto& w : version2) if (w == '.') w=' ';
        istringstream s1(version1), s2(version2);
        while(1) {
            int n1,n2;
            if (not(s1 >> n1) ) n1 = 0;
            if (not(s2 >> n2) ) n2 = 0;
            if (not s1 and not s2) return 0;
            if (n1<n2) return -1;
            if (n1>n2) return 1;
        }
    }
};


class Solution {
    //really a bad solution
public:
    vector<string> split(string str, char token){
        vector<string> result;
        int i = 0;
        string tmp = "";
        while(str[i] != '\0'){
            if(str[i] == token){
                if(tmp.length() > 0){
                    result.push_back(tmp);
                }
                tmp = "";
            }else{
                tmp += str[i];
            }
            i++;
        }
        if(tmp.length() > 0){
            result.push_back(tmp);
        }
        return result;
    }
    int compareVersion(string version1, string version2) {
        vector<string> strs1 = split(version1, '.');
        vector<string> strs2 = split(version2, '.');
        int i = 0;
        while(i < max(strs1.size(), strs2.size())){
            int a = (strs1.size() > i)? stoi(strs1[i]) : 0;
            int b = (strs2.size() > i)? stoi(strs2[i]) : 0;
            if(a > b){
                return 1;
            }else if(a < b){
                return -1;
            }
            ++i;
        }
        return 0;
    }
};