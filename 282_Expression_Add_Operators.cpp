//
//  282_Expression_Add_Operators.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/2/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;




class Solution2 {
    //DFS, faster and cleaner than Solution
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        DFS(result, num, target, "", 0, 0, 0);
        return result;
    }
    //cur: current processed prefix;  pos: current head;  value: value of 'cur';  right: right most operand in 'cur'
    void DFS(vector<string>& result, string& num, int target, string cur, int pos, long value, long right){
        if(pos >= num.size()){
            if(value == target && !cur.empty()){
                result.push_back(cur);
            }
            return;
        }
        for(int i = pos; i < num.size(); ++i){
            if(num[pos] == '0' && i > pos)      //a number can't start with 0 and length >= 2; e.g. '00', '05' are illegal
                break;
            string opStr = num.substr(pos, i - pos + 1);
            long opVal = stol(opStr);
            if(pos == 0){
                DFS(result, num, target, opStr, i + 1, opVal, opVal);   //shouldn't add operator at begining
            }else{
                DFS(result, num, target, cur+'+'+opStr, i + 1, value + opVal, opVal);
                DFS(result, num, target, cur+'-'+opStr, i + 1, value - opVal, -opVal);
                DFS(result, num, target, cur+'*'+opStr, i + 1, value - right + right * opVal, right * opVal);
            }
        }
    }
};



class Solution {
public:
    vector<string> final = {};
    
    int calProduct(string& s, int k, int n){
        string s_rtn = "";
        int i = 0;
        int j = 0;
        int product = 1;
        while(k > 0){
            if(k % 2 == 0){
                j++;
            }else{
                if(s[i] == '0' && j > i){
                    return -1;
                }
                product *= stol(s.substr(i, j - i + 1));
                s_rtn = s_rtn + s.substr(i, j - i + 1) + "*";
                i = j + 1;
                j = j + 1;
            }
            k /= 2;
        }
        
        if(s[i] == '0' && n - i > 1){
            return -1;
        }
        product *= stol(s.substr(i, n - i));
        s_rtn = s_rtn + s.substr(i, n - i);
        s = s_rtn;
        return product;
    }
    
    void DFS(string store, string remain, int target){
        if(remain.length() == 0){
            if(target == 0){
                final.push_back(store.substr(0));
            }
            return;
        }
        

        if(stol(remain) >= target && remain.length() >= 1){
            for(int i = 1; i <= remain.length(); i++){
                string mul = remain.substr(0, i);
                string new_remain = remain.substr(i);
                for(int j = 0; j < pow(2, i - 1); j++){
                    string new_mul = mul;
                    int product = calProduct(new_mul, j, i);
                    if(product < 0){
                        continue;
                    }
                    if(store != ""){
                        DFS(store + "+" + new_mul, new_remain, target - product);
                        DFS(store + "-" + new_mul, new_remain, target + product);
                    }else{
                        DFS(store + new_mul, new_remain, target - product);
                    }
                }
            }
        }
    }
    
    vector<string> addOperators(string num, int target) {
        final = {};
        DFS("", num, target);
        return final;
    }
};

/*
int main(void){
    Solution ss;
    vector<string> ans = ss.addOperators("123456789", 45);
    for(auto k : ans){
        cout << k << endl;
    }
    cout << "end" << endl;
}
*/
