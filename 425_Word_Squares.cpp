//
//  425_Word_Squares.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/3/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Node{
public:
    string str;
    Node* child[26];
    Node(){
        str = "";
        for(int i = 0; i < 26; ++i){
            child[i] = nullptr;
        }
    }
};
class Solution {
public:
    void insertNode(Node* root, string word){
        for(auto ch : word){
            if(!root->child[ch - 'a']){
                root->child[ch - 'a'] = new Node();
            }
            root = root->child[ch - 'a'];
        }
        root->str = word;
    }
    vector<string> findWordsWithPrefix(Node* root, string prefix, int len){
        vector<string> result;
        for(auto ch : prefix){
            if(!root->child[ch - 'a']){
                return result;
            }
            root = root->child[ch - 'a'];
        }
        findAllWords(result, root, len - (int)prefix.size());
        return result;
    }
    void findAllWords(vector<string>& result, Node* root, int len){
        if(len == 0){
            if(!root->str.empty()){
                result.push_back(root->str);
            }
            return;
        }else{
            for(int i = 0; i < 26; ++i){
                if(root->child[i]){
                    findAllWords(result, root->child[i], len - 1);
                }
            }
        }
        return;
    }
    Node* buildTrie(vector<string>& words){
        Node* root = new Node();
        for(auto word : words){
            insertNode(root, word);
        }
        return root;
    }
    void DFS(vector<vector<string>>& result, vector<string>& current, Node* root, int k, int len){
        if(k >= len){
            result.push_back(current);
            return;
        }
        string prefix = "";
        for(int i = 0; i < k; ++i){
            prefix += current[i][k];
        }
        vector<string> candids = findWordsWithPrefix(root, prefix, len);
        for(string candid : candids){
            current.push_back(candid);
            DFS(result, current, root, k + 1, len);
            current.pop_back();
        }
    }
    vector<vector<string>> wordSquares(vector<string>& words){
        Node* root = buildTrie(words);
        vector<vector<string>> result;
        if(words.empty()){
            return result;
        }
        int len = static_cast<int>(words[0].size());
        vector<string> current;
        DFS(result, current, root, 0, len);
        return result;
    }
};
