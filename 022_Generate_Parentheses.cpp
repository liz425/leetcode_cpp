//
//  22_Generate_Parentheses.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 3/19/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void genDFS(vector<string>& ss, int j, int k, int n, string sub){
        sub += '(';
        j++;
        if (j > n) {
            return;
        }
        else if(j == n){
            sub += string(n - k, ')');
            ss.push_back(sub);
        }else{
            for(int i = 0; i <= j - k; i++){
                int new_k = k + i;
                string new_sub = sub + string(i, ')');
                genDFS(ss, j, new_k, n, new_sub);
            }
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ss;
        string sub = "";
        genDFS(ss, 0, 0, n, sub);
        return ss;
    }
};

//int main(void){
//    Solution sol;
//    vector<string> ss =  sol.generateParenthesis(6);
//    for (int i = 0; i < ss.size(); i++) {
//        cout << ss[i] << endl;
//    }
//    cout << ss.size() << endl;
//}
