//
//  105_Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 6/21/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution3 {
public:
    //AC. Faster than Solution2.s
    //Convert vector<int>& inorder into a unordered_map, accelerate finding process.
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> hmap;
        int len = (int)inorder.size();
        for(int i = 0; i < len; ++i){
            hmap[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, 0, (int)preorder.size(), hmap, 0, (int)inorder.size());
    }
    
    TreeNode* buildTreeHelper(vector<int>& preorder, int i, int j, unordered_map<int, int>& hmap, int p, int q){
        if(i >= j){
            return NULL;
        }
        TreeNode* current = new TreeNode(preorder[i]);
        int me = hmap[preorder[i]];
        int left = int(me - p);
        current->left = buildTreeHelper(preorder, i + 1, i + 1 + left, hmap, p, me);
        current->right = buildTreeHelper(preorder, i + 1 + left, j, hmap, me + 1, q);
        return current;
    }
};


class Solution2 {
public:
    //AC. Reference to the original vector rather than copy a new one.
    //However, find() in vector is slow.
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder, 0, (int)preorder.size(), inorder, 0, (int)inorder.size());
    }
    
    TreeNode* buildTreeHelper(vector<int>& preorder, int i, int j, vector<int>& inorder, int p, int q){
        if(i >= j){
            return NULL;
        }
        TreeNode* current = new TreeNode(preorder[i]);
        int me = int(find(inorder.begin(), inorder.end(), preorder[i]) - inorder.begin());
        int left = int(me - p);
        current->left = buildTreeHelper(preorder, i + 1, i + 1 + left, inorder, p, me);
        current->right = buildTreeHelper(preorder, i + 1 + left, j, inorder, me + 1, q);
        return current;
    }
};


class Solution {
public:
    //Memory Limit Exceeded, cause we made a copy of the vectors in every recurrsion.
    //Recurrsive solution
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()){
            return NULL;
        }
        TreeNode* current = new TreeNode(preorder[0]);
        vector<int>::iterator me = find(inorder.begin(), inorder.end(), preorder[0]);
        int left = int(me - inorder.begin());
        vector<int> v1(preorder.begin() + 1, preorder.begin() + 1 + left);
        vector<int> v2(inorder.begin(), me);
        current->left = buildTree(v1, v2);
        v1.clear();
        v1 = vector<int>(preorder.begin() + 1 + left, preorder.end());
        v2.clear();
        v2 = vector<int>(me + 1, inorder.end());
        current->right = buildTree(v1, v2);
        return current;
    }
};

