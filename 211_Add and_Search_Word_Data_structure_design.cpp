//
//  211_Add and_Search_Word_Data_structure_design.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/6/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class WordDictionary {
public:
    struct Node{
        Node* child[26];
        bool isKey;
        Node(){
            isKey = false;
            memset(child, NULL, sizeof(Node*) * 26);
        }
    };
    Node* root;
    WordDictionary(){
        root = new Node();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        Node* p = root;
        for(char ch: word){
            if(!p->child[ch-'a'])
                p->child[ch-'a'] = new Node();
            p = p->child[ch-'a'];
        }
        p->isKey = true;
    }
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool DFS(Node* root, string word, int index){
        for(int i = index; i < word.size(); ++i){
            if(!root){
                return false;
            }else if(word[i] == '.'){
                for(int j = 0; j < 26; ++j){
                    if(DFS(root->child[j], word, i + 1))
                        return true;
                }
                return false;
            }else{
                root = root->child[word[i] - 'a'];
            }
        }
        return root && root->isKey;
    }
    bool search(string word) {
        return DFS(root, word, 0);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
