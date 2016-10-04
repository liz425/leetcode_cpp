//
//  307_Range_Sum_Query_Mutable.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/14/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class NumArray {
public:
    //use segment tree to support update
    vector<int> tree;
    int size = 0;
    NumArray(vector<int> &nums) {
        size = (int)nums.size();
        if(size == 0)
            return;
        int treeSize = pow(2, (int)log2(size));
        treeSize = (treeSize == size)? treeSize * 2 : treeSize * 4;
        tree.resize(treeSize, 0);
        buildTree(nums, 0, 0, size - 1);
    }
    void buildTree(vector<int>& nums, int treeIndex, int lo, int hi){
        if(lo == hi){
            tree[treeIndex] = nums[lo];
            return;
        }
        int mid = lo + (hi - lo) / 2;
        buildTree(nums, treeIndex * 2 + 1, lo, mid);
        buildTree(nums, treeIndex * 2 + 2, mid + 1, hi);
        tree[treeIndex] = merge(tree[treeIndex * 2 + 1], tree[treeIndex * 2 + 2]);
    }
    int merge(int left, int right){
        return left + right;
    }
    void update(int i, int val) {
        updateTreeNode(i, val, 0, 0, size - 1);
    }
    void updateTreeNode(int i , int val, int treeIndex, int lo, int hi){
        if(lo == hi){
            tree[treeIndex] = val;
            return;
        }
        int mid = lo + (hi - lo) / 2;
        if(i <= mid)
            updateTreeNode(i, val, treeIndex * 2 + 1, lo, mid);
        else
            updateTreeNode(i, val, treeIndex * 2 + 2, mid + 1, hi);
        tree[treeIndex] = merge(tree[treeIndex * 2 + 1], tree[treeIndex * 2 + 2]);
    }
    int sumRange(int i, int j) {
        if(size == 0) return 0;
        return queryTree(0, i, j, 0, size - 1);
    }
    int queryTree(int treeIndex, int i, int j, int lo, int hi){
        if(i > hi || j < lo){
            return 0;
        }
        if(i <= lo && j >= hi){
            return tree[treeIndex];
        }
        int mid = lo + (hi - lo) / 2;
        if(i > mid )
            return queryTree(treeIndex * 2 + 2, i, j, mid + 1, hi);
        if(j <= mid)
            return queryTree(treeIndex * 2 + 1, i, j, lo, mid);
        
        int leftQuery = queryTree(treeIndex * 2 + 1, i, mid, lo, mid);
        int rightQuery = queryTree(treeIndex * 2 + 2, mid + 1, j, mid + 1, hi);
        return merge(leftQuery, rightQuery);
    }
};


/*
int main(){
    vector<int> nums = {-28,-39,53,65,11,-56,-65,-39,-43,97};
    NumArray numArray(nums);
    cout << numArray.sumRange(5,6) << endl;
    numArray.update(9,27);
    cout << numArray.sumRange(2,3) << endl;
    cout << numArray.sumRange(6,7) << endl;
    numArray.update(1,-82);
    numArray.update(3,-72);
    cout << numArray.sumRange(3,7) << endl;
    cout << numArray.sumRange(1,8) << endl;
    numArray.update(5,13);
    numArray.update(4,-67);
    return 1;
}
*/
