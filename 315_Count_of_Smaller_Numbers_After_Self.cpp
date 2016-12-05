//
//  315_Count_of_Smaller_Numbers_After_Self.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/18/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution3 {
    //BIT
    //Use nums to store the final position of the original nums[i], this can be obtained after sort the original array
    //and use binary search
    //When build BIT, put each element in its final position, and query the tree to know how many smaller node already exist
public:
    void add(vector<int>& BIT, int i, int val){
        for(; i < BIT.size(); i += (-i & i)){
            BIT[i] += val;
        }
    }
    int query(vector<int>& BIT, int i){
        int ans = 0;
        for(; i > 0; i -= (-i & i)){
            ans += BIT[i];
        }
        return ans;
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        int n = (int)nums.size();
        for(int i = 0; i < n; ++i){
            nums[i] = int(lower_bound(tmp.begin(), tmp.end(), nums[i]) - tmp.begin()) + 1;
        }
        vector<int> BIT = vector<int>(n + 1, 0);
        vector<int> ans(n, 0);
        for(int i = n - 1; i >= 0; --i){
            ans[i] = query(BIT, nums[i] - 1);
            add(BIT, nums[i], 1);
        }
        return ans;
    }
};



class Solution2 {
    //O(n^2), TLE; Segment Tree
private:
    vector<int> tree;
    void update(int treeIndex, int numIndex, int val, int i, int j){
        if(i == j){
            tree[treeIndex] = val;
            return;
        }else{
            int mid = i + (j - i) / 2;
            if(numIndex <= mid){
                update(treeIndex * 2 + 1, numIndex, val, i, mid);
            }else{
                update(treeIndex * 2 + 2, numIndex, val, mid + 1, j);
            }
            tree[treeIndex] = merge(tree[treeIndex * 2 + 1], tree[treeIndex * 2 + 2]);
        }
    }
    int merge(int left, int right){
        return min(left, right);
    }
    int queryNode(int treeIndex, int val, int i, int j){
        if(tree[treeIndex] >= val){
            return 0;
        }else if(i == j){
            return 1;
        }
        int sum = 0;
        int mid = i + (j - i) / 2;
        sum += queryNode(treeIndex * 2 + 1, val, i, mid);
        sum += queryNode(treeIndex * 2 + 2, val, mid + 1, j);
        return sum;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> result(n, 0);
        if(nums.empty())
            return result;
        int treeSize = pow(2, ceil(log2((int)nums.size())) + 1);
        tree = vector<int>(treeSize, INT_MAX);
        for(int i = n - 1; i >= 0; --i){
            result[i] = queryNode(0, nums[i], 0, n - 1);
            update(0, i, nums[i], 0, n - 1);
        }
        return result;
    }
};



class Solution {
    //T = O(n * logn)
private:
    vector<int> result;
    void mergeSort(vector<pair<int, int>>& numIndex){
        int k = (int)numIndex.size();
        if(k <= 1){
            return;
        }
        int m = k / 2;
        int n = k - m;
        vector<pair<int, int>> left(numIndex.begin(), numIndex.begin() + m);
        vector<pair<int, int>> right(numIndex.begin() + m, numIndex.end());
        mergeSort(left);
        mergeSort(right);
        int i = 0;
        int j = 0;
        while(j < n || i < m){
            if(j < n && (i >= m || right[j].first < left[i].first)){
                numIndex[i + j] = right[j];
                j++;
            }else{
                numIndex[i + j] = left[i];
                result[numIndex[i + j].second] += j;
                i++;
            }
        }
        return;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> numIndex;
        int n = (int)nums.size();
        result = vector<int>(n, 0);
        for(int i = 0; i < n; ++i){
            numIndex.push_back(make_pair(nums[i], i));
        }
        mergeSort(numIndex);
        return result;
    }
};


/*
int main(){
    Solution3 ss;
    vector<int> nums = {26,78,27,100,33,67,90,23,66,5,3};
    vector<int> result = ss.countSmaller(nums);
    int n = (int)nums.size();
    for(int i = 0; i < n; ++i){
        cout << result[i] << endl;
    }
}
*/
