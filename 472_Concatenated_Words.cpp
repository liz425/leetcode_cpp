//
//  472_Concatenated_Words.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/18/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
    //Pass.
public:
    bool isCombine(string& word, unordered_set<string>& hm){
        int n = (int)word.size();
        if(n == 0){
            return false;
        }
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for(int i = 1; i <= n; ++i){
            int start = (i == n)? 1 : 0;
            //should search from back to front. Thus the substr is firstly small.
            //The shorter the string is, the less time is takes to find.
            for(int j = i - 1; j >= start; --j){
                if(dp[j] && hm.find(word.substr(j, i - j)) != hm.end()){
                    dp[i] = true;
                    hm.insert(word.substr(0, i));
                    break;
                }
            }
        }
        return dp[n];
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> result;
        int n = (int)words.size();
        unordered_set<string> hm;
        for(string& word : words){
            hm.insert(word);
        }
        for(int i = 0; i < n; ++i){
            if(isCombine(words[i], hm)){
                result.push_back(words[i]);
            }
        }
        return result;
    }
};




class TrieNode{
    //TLE or MLE. Do not use trie here
public:
    bool isStr;
    unordered_map<char, TrieNode*> child;
    TrieNode(){
        isStr = false;
    }
};

class Solution {
public:
    TrieNode* buildTrie(const vector<string>& words){
        TrieNode* root = new TrieNode();
        for(const string& word : words){
            insertWord(word, root);
        }
        return root;
    }
    void insertWord(const string& word, TrieNode* root){
        for(char ch : word){
            if(root->child.find(ch) == root->child.end()){
                root->child[ch] = new TrieNode();
            }
            root = root->child[ch];
        }
        root->isStr = true;
    }
    bool isWord(const string& word, TrieNode* root){
        for(char ch : word){
            if(root->child.find(ch) == root->child.end()){
                return false;
            }
            root = root->child[ch];
        }
        return root->isStr;
    }
    bool isCombine(string& word, TrieNode* root){
        int n = (int)word.size();
        if(n == 0){
            return false;
        }
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for(int i = 1; i <= n; ++i){
            int start = (i == n)? 1 : 0;
            for(int j = i - 1; j >= start; --j){
                if(dp[j] && isWord(word.substr(j, i - j), root)){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
//        auto comp = [](string a, string b) -> bool{
//            return a.size() < b.size();
//        };
        //sort(words.begin(), words.end(), comp);
        vector<string> result;
        TrieNode* root = buildTrie(words);
        int n = (int)words.size();
        for(int i = 0; i < n; ++i){
            insertWord(words[i], root);
            if(isCombine(words[i], root)){
                result.push_back(words[i]);
            }
        }
        return result;
    }
};
