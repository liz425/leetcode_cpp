//
//  UndirectedGraphNode.h
//  leetcode_cpp
//
//  Created by Zhen Li on 11/13/16.
//  Copyright © 2016 zl. All rights reserved.
//

#ifndef UndirectedGraphNode_h
#define UndirectedGraphNode_h

/* Definition for undirected graph. */
struct UndirectedGraphNode {
    int label;
    std::vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};



#endif /* UndirectedGraphNode_h */
