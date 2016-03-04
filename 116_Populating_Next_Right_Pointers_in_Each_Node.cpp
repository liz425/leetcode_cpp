//
//  116_Populating_Next_Right_Pointers_in_Each_Node.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 3/1/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <math.h>
using namespace std;

/**/
//Definition for binary tree with next pointer.
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

// Iteration, time O(n), space O(1)
class Solution3 {
public:
  void connect(TreeLinkNode *root) {
    while(root != NULL){
      TreeLinkNode* horizontal = root;
      if(root->left == NULL)
        break;
      while(horizontal != NULL){
        horizontal->left->next = horizontal->right;
        if(horizontal->next != NULL){
          horizontal->right->next = horizontal->next->left;
        }
        horizontal = horizontal->next;
      }
      root = root->left;
    }
  }
};

// Iteration, time O(n), space O(1)
class Solution2 {
public:
  void connect(TreeLinkNode* root) {
    if (root == NULL){
      return;
    }
  
    if (root->left != NULL){
      root->left->next = root->right;
      if (root->next != NULL){
        root->right->next = root->next->left;
      }
    }
  
    connect(root->left);
    connect(root->right);
  }
};

class Solution {
public:
  void connect(TreeLinkNode *root) {
    TreeLinkNode* next = root;
    int level = 0;
    while(next != NULL){
      int j = 0;
      TreeLinkNode* tmp;
      for(j = 0; j < pow(2,level) - 1; j++){
        tmp = getnode(root, level, j);
        tmp->next = getnode(root, level, j + 1);
      }
      tmp = getnode(root, level, j);
      tmp->next = NULL;
      level++;
      next = next->left;
    }
  }
  
  TreeLinkNode* getnode(TreeLinkNode *current, int level, int index){
    for(int i = 1; i <= level; i++){
      if(index & (0x1 << (level - i))){
        current = current->right;
      }else{
        current = current->left;
      }
    }
    return current;
  }
};

