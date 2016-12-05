
//
//  140_Word_Break_II.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/2/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"



class Solution2 {
    void DFS(vector<string>& result, vector<vector<int>>& dp, string current, int n, int start, string s){
        if(start >= n){
            if(!current.empty()){
                result.push_back(current.substr(1));
            }
            return;
        }
        for(int k : dp[start]){
            DFS(result, dp, current + " " + s.substr(start, k - start), n, k, s);
        }
    }
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int n = (int)s.size();
        vector<vector<int>> dp(n + 1, vector<int>(0));
        vector<string> result;
        dp[n] = {n};
        for(int i = n - 1; i >= 0; --i){
            for(int j = i; j < n; ++j){
                if(!dp[j + 1].empty() && wordDict.find(s.substr(i, j - i + 1)) != wordDict.end()){
                    dp[i].push_back(j + 1);
                }
            }
        }
        DFS(result, dp, "", n, 0, s);
        return result;
    }
};



class Solution {
    //MLE, casue we store two much stringss
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int n = (int)s.size();
        vector<vector<string>> dp(n + 1, vector<string>(0));
        if(s.empty()){
            return dp[0];
        }
        dp[0] = vector<string>{""};
        vector<int> prefixIndex = {0};      //indicate those position pre that  we have a partition from head to pre
        for(int i = 1; i <= n; ++i){
            for(int pre : prefixIndex){     //pre: lens of prefix
                string subS = s.substr(pre, i - pre);   //substr(), index from 0, so s.substr(pre) is from next char after pre
                if(wordDict.find(subS) != wordDict.end()){
                    for(string str : dp[pre]){
                        if(str.empty()){
                            dp[i].push_back(subS);
                        }else{
                            dp[i].push_back(str + " " + subS);
                        }
                    }
                }
            }
            if(!dp[i].empty()){
                prefixIndex.push_back(i);
            }
        }
        return dp[n];
    }
};


/*
int main(){
    Solution2 ss;
    string in = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    string in2 = "catsanddog";
    unordered_set<string> wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    unordered_set<string> wordDict2 = {"cat","cats","and","sand","dog"};
    ss.wordBreak(in2, wordDict2);
}
*/
