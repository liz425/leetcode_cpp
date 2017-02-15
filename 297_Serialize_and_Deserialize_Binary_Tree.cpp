//
//  297_Serialize_and_Deserialize_Binary_Tree.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/21/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Codec2 {
    //Recurrsive solution. Pre-order traversal
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        serializeHelper(root, result);
        return result;
    }
    void serializeHelper(TreeNode* root, string& result){
        if(!root){
            result += "#,";
        }else{
            result += to_string(root->val) + ",";
            serializeHelper(root->left, result);
            serializeHelper(root->right, result);
        }
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return deserializeHelper(data, index);
    }
    TreeNode* deserializeHelper(string& data, int& index){
        string node = "";
        while(data[index] != ','){
            node += data[index++];
        }
        index++;
        if(node == "#"){
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(node));
        root->left = deserializeHelper(data, index);
        root->right = deserializeHelper(data, index);
        return root;
    }
};




class Codec {
    //BFS solution. Non-recurrsive solution
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        queue<TreeNode*> level;
        level.push(root);
        while(!level.empty()){
            TreeNode *cur = level.front();
            level.pop();
            if(!cur){
                result += "#,";
            }else{
                result += to_string(cur->val) + ",";
                level.push(cur->left);
                level.push(cur->right);
            }
        }
        return result;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string node = "";
        for(char ch : data){
            if(ch == ','){
                nodes.push_back(node);
                node = "";
            }else{
                node += ch;
            }
        }
        
        if(!nodes.empty() && nodes[0] == "#"){
            return NULL;
        }
        queue<TreeNode*> level;
        TreeNode *root = new TreeNode(stoi(nodes[0]));
        level.push(root);
        int cnt = 1;
        while(!level.empty()){
            TreeNode *cur = level.front();
            level.pop();
            string left = nodes[cnt++];
            string right = nodes[cnt++];
            if(left == "#")
                cur->left = NULL;
            else{
                cur->left = new TreeNode(stoi(left));
                level.push(cur->left);
            }
            if(right == "#")
                cur->right = NULL;
            else{
                cur->right = new TreeNode(stoi(right));
                level.push(cur->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
