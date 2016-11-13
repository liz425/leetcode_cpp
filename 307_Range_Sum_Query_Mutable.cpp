//
//  307_Range_Sum_Query_Mutable.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/14/16.
//  Copyright © 2016 zl. All rights reserved.
//


#include "inc.h"


class NumArray2 {
    //BIT solution
private:
    vector<int> tree;   //BIT tree, index from 1
    int maxSize;
public:
    NumArray2(vector<int> &nums) {
        maxSize = (int)nums.size();
        tree.assign(maxSize + 1, 0);
        for(int i = 0; i < maxSize; ++i){
            add(i, nums[i]);
        }
    }
    
    //add delta to nums[i]
    void add(int idx, int delta){
        idx++;
        while(idx <= maxSize){
            tree[idx] += delta;
            idx += (-idx & idx);
        }
    }
    
    //query the actually value on nums[i]
    //also we could use an reference vector<int>& _nums = nums;
    //then we could directly modify and access nums[i] through _nums[i]
    int queryNode(int idx){
        idx++;
        int sum = tree[idx];
        int preIdx = idx - (-idx & idx);
        idx--;  //here is an assumption that idx > 0. then after idx--, idx won't be negtive
        while(idx != preIdx){
            sum -= tree[idx];
            idx -= (-idx & idx);
        }
        return sum;
    }
    void update(int i, int val) {
        int delta = val - queryNode(i);
        add(i, delta);
    }
    int querySum(int idx){
        idx++;  //tree index from 1, but nums index from 0
        int sum = 0;
        while(idx > 0){
            sum += tree[idx];
            idx -= (-idx & idx);
        }
        return sum;
    }
    int sumRange(int i, int j) {
        return querySum(j) - querySum(i - 1);
    }
};


class NumArray {
public:
    //use segment tree to support update
    vector<int> tree;
    int size = 0;
    NumArray(vector<int> &nums) {
        size = (int)nums.size();
        if(size == 0)
            return;
        //should check if n == 0, since log2(0) is invalid
        int treeSize = pow(2, ceil(log2(size)) + 1);
        tree.assign(treeSize, 0);
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
        if(i > hi || i < lo){
            return;
        }else if(lo == hi){
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
