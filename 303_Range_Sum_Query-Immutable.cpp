//
//  303_Range_Sum_Query-Immutable.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/23/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <iostream>
using namespace std;

class NumArray2 {
    //use malloc is faster than vector
public:
    int* SFF;//sum from first
    NumArray2(vector<int> &nums) {
        int sum = 0;
        SFF = (int*)calloc(4, nums.size() + 1);
        SFF[0] = 0;
        for(int i = 0; i < (int)nums.size(); i++){
            sum += nums[i];
            SFF[i + 1] = sum;
        }
    }
    
    int sumRange(int i, int j) {
        return SFF[j + 1] - SFF[i];
    }
};


class NumArray {
public:
    vector<int> SFF;//sum from first
    NumArray(vector<int> &nums) {
        int sum = 0;
        for(int i = 0; i < (int)nums.size(); i++){
            sum += nums[i];
            SFF.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        return (i > 0)? SFF[j] - SFF[i - 1]: SFF[j];
    }
};

/*
int main(){
    vector<int> v {1,2,3,4,5,6,7,8,9};
    NumArray ss(v);
    cout << ss.sumRange(4, 6) << endl;
}
 */
