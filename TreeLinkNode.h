//
//  TreeLinkNode.h
//  leetcode_cpp
//
//  Created by 李镇 on 4/6/16.
//  Copyright © 2016 zl. All rights reserved.
//

#ifndef TreeLinkNode_h
#define TreeLinkNode_h

/* Definition for binary tree with next pointer. */
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

#endif /* TreeLinkNode_h */
