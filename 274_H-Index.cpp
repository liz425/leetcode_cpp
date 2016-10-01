//
//  274_H-Index.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 5/30/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <functional>
#include <vector>
using namespace std;
class Solution2 {
    //time: O(n), space: O(n)
public:
    int hIndex(vector<int>& citations) {
        int size = (int)citations.size();
        vector<int> h(size + 1, 0);
        for(int& c : citations){
            if(c >= size){
                ++h[size];
            }else{
                ++h[c];
            }
        }
        int sum = 0;
        int i = 0;
        for(i = size; i >= 0; --i){
            if(i > sum + h[i]){
                sum += h[i];
            }else{
                break;
            }
        }
        return i;
    }
};


class Solution {
    //time: O(n*logn), space: O(1)
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int size = (int)citations.size();
        int i = 0;
        for(i = 0; i < size; ++i){
            if(citations[i] < i + 1)
                break;
        }
        return i;
    }
};