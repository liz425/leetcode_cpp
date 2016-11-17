//
//  208_Implement_Trie_(Prefix_Tree).cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/15/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode* child[26];
    string str;
    TrieNode() {
        for(int i = 0; i < 26; ++i){
            child[i] = NULL;
        }
        str = "";
    }
};

class Trie {
    //Remember to write destructor in case of memory leaks
public:
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie(){
        deleteTrie(root);
    }
    
    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* cur = root;
        for(char ch : word){
            if(cur->child[ch - 'a'] == NULL){
                cur->child[ch - 'a'] = new TrieNode();
            }
            cur = cur->child[ch - 'a'];
        }
        cur->str = word;
    }
    
    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* p = find(word);
        return (p != NULL && !p->str.empty());
    }
    
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* p = find(prefix);
        return p != NULL;
    }
    
private:
    TrieNode* root;
    TrieNode* find(string word){
        TrieNode* cur = root;
        for(char ch : word){
            if(cur->child[ch - 'a'] == NULL){
                return NULL;
            }
            cur = cur->child[ch - 'a'];
        }
        return cur;
    }
    void deleteTrie(TrieNode* root){
        if(root == NULL){
            return;
        }
        for(int i = 0; i < 26; ++i){
            deleteTrie(root->child[i]);
        }
        delete root;
        return;
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
