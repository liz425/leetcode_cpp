//
//  020_Valid_Parentheses.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/20/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <stack>
using namespace std;

class Solution2 {
    //More concise than Solution1
public:
    bool isPair(char a, char b){
        return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}');
    }
    bool isValid(string s) {
        stack<char> pre;
        for(char ch : s){
            if(ch == '(' || ch == '[' || ch == '{')
                pre.push(ch);
            else if(pre.empty() || !isPair(pre.top(), ch))
                return false;
            else
                pre.pop();
        }
        return pre.empty();
    }
};


//when using stack, every time when pop(), should check if it's empty() at first
class Solution {
public:
    bool isValid(string s) {
        stack<char> q;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                q.push(s[i]);
            }else{
                //if q is empty, right parentheses could NOT find according left parentheses, false
                if(q.empty()){
                    return false;
                }
                char x = q.top();
                q.pop();
                if((x == '{' && s[i] != '}') || (x == '[' && s[i] != ']') || (x == '(' && s[i] != ')')){
                    return false;
                }
            }
        }
        //if q is NOT empty, remaining left parentheses exists, false
        return q.empty();
    }
};
