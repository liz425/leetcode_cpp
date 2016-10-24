//
//  333_Largest_BST_Subtree.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/22/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
    //User INT_MAX and INT_MIN to process NULL nodes, more concise
public:
    int largestBSTSubtree(TreeNode* root) {
        if(!root)
            return 0;
        dfs(root);
        return maxN;
    }
private:
    int maxN = 0;
    vector<int> dfs(TreeNode* root){
        if(!root)
            return vector<int>{0, INT_MAX, INT_MIN}; //{subtree_size, lower_bound, upper_bound}.
        vector<int> l = dfs(root->left);
        vector<int> r = dfs(root->right);
        if(l[0] == -1 || r[0] == -1 || l[2] >= root->val || r[1] <= root->val)
            return vector<int>{-1, 0, 0};
        maxN = max(maxN, l[0] + r[0] + 1);
        return vector<int>{l[0] + r[0] + 1, min(l[1], root->val), max(r[2], root->val)};
    }
};



class Solution {
public:
    int maxN;
    int largestBSTSubtree(TreeNode* root) {
        if(!root){
            return 0;
        }else{
            maxN = 0;
            DFS(root);
            return maxN;
        }
    }
    tuple<int, int, int> DFS(TreeNode* root){   //tuple: valid_nodes, min_val, max_val
        if(!root)
            return make_tuple(0, 0, 0);
        int node = 1;
        int min_val = root->val;
        int max_val = root->val;
        bool valid = true;
        if(root->left){
            auto left = DFS(root->left);
            if(get<0>(left) > 0 && get<2>(left) < root->val){
                node += get<0>(left);
                min_val = get<1>(left);
            }else{          //root->left is a invalid BST, so root is also invalid, but we need to explorer root->right
                valid = false;
            }
        }
        if(root->right){
            auto right = DFS(root->right);
            if(get<0>(right) > 0 && get<1>(right) > root->val){
                node += get<0>(right);
                max_val = get<2>(right);
            }else{          //root->right is a invalid BST, so root is also invalid
                valid = false;
            }
        }
        if(!valid)
            node = -1;
        maxN = max(maxN, node);
        return make_tuple(node, min_val, max_val);
    }
};
