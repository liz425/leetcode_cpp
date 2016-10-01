//
//  347_Top_K_Frequent_Elements.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 7/17/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution {
    //Notice that operator()(<) will constructor a max_heap
    //Cause operator()(<) defines a strict weak ordering that larger item goes later
    //While priority_queue<,, comp> will preserve heap by poping the latest item, i.e. the largest one
    //So it will construct a max_heap 
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for(int& num : nums){
            hash[num] += 1;
        }
        struct node{
            int cnt;
            int val;
            node(int v, int c){
                cnt = c;
                val = v;
            }
        };
        struct comp{
            bool operator()(node a, node b){
                return (a.cnt < b.cnt);
            }
        };
        priority_queue<node, vector<node>, comp> heap;
        for(auto& item : hash){
            heap.push(node(item.first, item.second));
        }
        vector<int> result;
        for(int i = 0; i < k; ++i){
            result.push_back(heap.top().val);
            heap.pop();
        }
        return result;
    }
};
