//
//  211_Add_and_Search_Word_Data_structure_design.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/1/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class WordDictionary2 {
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
    WordDictionary2(){
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



class WordDictionary {
public:
    struct node{
        bool isKey;
        vector<node*> children;
        node(){
            isKey = false;
            children = vector<node*>(26, NULL);
        }
    };
    
    node* root;
    WordDictionary(){
        root = new node();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        node* current = root;
        for(auto& ch : word){
            if(!current->children[ch - 'a']){
                current->children[ch - 'a'] = new node();
            }
            current = current->children[ch - 'a'];
        }
        current->isKey = true;
    }
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchHelper(word, root);
    }
    bool searchHelper(string word, node* current){
        if(word.empty()){
            return current->isKey;
        }else if(word[0] == '.'){
            for(auto& child : current->children){
                if(child && searchHelper(word.substr(1), child))
                    return true;
            }
            return false;
        }else{
            node* child = current->children[word[0] - 'a'];
            return (child && searchHelper(word.substr(1), child));
        }
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
