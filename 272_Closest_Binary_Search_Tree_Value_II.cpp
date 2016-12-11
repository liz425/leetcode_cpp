//
//  272_Closest_Binary_Search_Tree_Value_II.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/6/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution3 {
    //inorder traversal.
    //T = O(n). Solution2 has better time complexity, but Solution3 is easier to understand
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        deque<int> ans;
        helper(root, target, k, ans);
        vector<int> result(ans.begin(), ans.end());
        return result;
    }
    void helper(TreeNode* root, double target, int k, deque<int>& ans){
        if(root == NULL || (ans.size() == k && abs(ans.back() - target) > abs(ans.front() - target))){
            //Notice, must be '>' here, not '>=', since if k == 1, ans.front() == ans.back(), but current ans may not be closest
            return;
        }
        helper(root->left, target, k, ans);
        ans.push_back(root->val);
        if(ans.size() > k){
            if(abs(ans.front() - target) > abs(ans.back() - target)){
                ans.pop_front();
            }else{
                ans.pop_back();
            }
        }
        helper(root->right, target, k, ans);
    }
};


class Solution2 {
    //InitStk: O(logn)
    //getPredecessor, getSuccessor: amortized O(1) operation
    //So, total T = O(logn) + O(k) = O(logn + k)
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        stack<TreeNode*> preStk, sucStk;
        initStack(root, target, preStk, sucStk);
        vector<int> result;
        while(k-- > 0){
            if(sucStk.empty() || (!preStk.empty() && target - preStk.top()->val < sucStk.top()->val - target)){
                result.push_back(preStk.top()->val);
                getPredecessor(preStk);
            }else{
                result.push_back(sucStk.top()->val);
                getSuccessor(sucStk);
            }
        }
        return result;
    }
    void initStack(TreeNode* root, double target, stack<TreeNode*>& preStk, stack<TreeNode*>& sucStk){
        while(root){
            if(root->val <= target){
                preStk.push(root);
                root = root->right;
            }else{
                sucStk.push(root);
                root = root->left;
            }
        }
    }
    void getPredecessor(stack<TreeNode*>& preStk){
        if(preStk.empty())
            return;
        TreeNode* cur = preStk.top();
        preStk.pop();
        if(cur->left){
            preStk.push(cur->left);
            while(preStk.top()->right){
                preStk.push(preStk.top()->right);
            }
        }
    }
    void getSuccessor(stack<TreeNode*>& sucStk){
        if(sucStk.empty())
            return;
        TreeNode* cur = sucStk.top();
        sucStk.pop();
        if(cur->right){
            sucStk.push(cur->right);
            while(sucStk.top()->left){
                sucStk.push(sucStk.top()->left);
            }
        }
    }
};


class Solution {
    //Ugly code. Basic same complexity with solution2
public:
    TreeNode* getPredecessor(stack<pair<TreeNode*, bool>>& preStk){
        if(preStk.empty()){
            return 0;
        }
        TreeNode* root = preStk.top().first;
        if(root->left){
            root = root->left;
            preStk.push(make_pair(root, true));
            while(root->right){
                root = root->right;
                preStk.push(make_pair(root, false));
            }
            return root;
        }else{
            while(!preStk.empty() && preStk.top().second){
                preStk.pop();
            }
            if(!preStk.empty()){
                preStk.pop();
                return preStk.top().first;
            }else{
                return NULL;
            }
        }
    }
    TreeNode* getSuccessor(stack<pair<TreeNode*, bool>>& sucStk){
        if(sucStk.empty()){
            return 0;
        }
        TreeNode* root = sucStk.top().first;
        if(root->right){
            root = root->right;
            sucStk.push(make_pair(root, true));
            while(root->left){
                root = root->left;
                sucStk.push(make_pair(root, false));
            }
            return root;
        }else{
            while(!sucStk.empty() && sucStk.top().second){
                sucStk.pop();
            }
            if(!sucStk.empty()){
                sucStk.pop();
                return sucStk.top().first;
            }else{
                return NULL;
            }
        }
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        stack<pair<TreeNode*, bool>> preStk;    //to get predecessor, bool: isLeft
        stack<pair<TreeNode*, bool>> sucStk;    //to get successor, bool: isRight
        vector<int> result;
        if(!root || k <= 0){
            return result;
        }
        deque<int> dq = {root->val};
        preStk.push(make_pair(root, true));
        sucStk.push(make_pair(root, true));
        bool leftBorder = false;
        bool rightBorder = false;
        while(!leftBorder || !rightBorder){
            TreeNode* tn;
            if((!leftBorder && (abs(dq.front() - target) < abs(dq.back() - target) || (dq.size() == 1 && target < dq.front()))) || rightBorder){
                tn = getPredecessor(preStk);
                if(tn != NULL){
                    dq.push_front(tn->val);
                }else{
                    leftBorder = true;
                }
            }else{
                tn = getSuccessor(sucStk);
                if(tn != NULL){
                    dq.push_back(tn->val);
                }else{
                    rightBorder = true;
                }
            }
            if(dq.size() > k){
                if(abs(dq.front() - target) < abs(dq.back() - target)){
                    dq.pop_back();
                }else{
                    dq.pop_front();
                }
                if(tn->val != dq.front() && tn->val != dq.back()){
                    break;
                }
            }
        }
        result = vector<int>(dq.begin(), dq.end());
        return result;
    }
};

/*
int main(void){
    Solution3 ss;
    vector<int> input = {1};
    TreeNode* root = new TreeNode(input[0]);
    for(int i = 1; i < (int)input.size(); ++i){
        TreeNode* cur = root;
        while(cur != NULL){
            if(input[i] < cur->val){
                if(cur->left){
                    cur = cur->left;
                }else{
                    cur->left = new TreeNode(input[i]);
                    break;
                }
            }else{
                if(cur->right){
                    cur = cur->right;
                }else{
                    cur->right = new TreeNode(input[i]);
                    break;
                }
            }
        }
    }
    vector<int> result = ss.closestKValues(root, 0, 1);
    for(int item : result){
        cout << item << endl;
    }
}
*/
