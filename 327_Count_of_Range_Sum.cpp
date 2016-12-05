//
//  327_Count_of_Range_Sum.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/21/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"



class Solution {
private:
    vector<int> BIT;
    void update(int n, int i, int val){
        while(i <= n){
            BIT[i] += val;
            i += (-i & i);
        }
    }
    int query(int i){
        int result = 0;
        while(i > 0){
            result += BIT[i];
            i -= (-i & i);
        }
        return result;
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = (int)nums.size();
        vector<long> sums(n + 1, 0);
        long sum = 0;
        for(int i = 0; i < n; ++i){
            sum += nums[i];
            sums[i] = sum;
        }
        sort(sums.begin(), sums.end());
        BIT = vector<int>(n + 2, 0);
        int result = 0;
        sum = 0;
        int sumIndex = int(lower_bound(sums.begin(), sums.end(), 0) - sums.begin());
        update(n + 1, sumIndex + 1, 1);
        for(int i = 0; i < n; ++i){
            sum += nums[i];
            //update BIT tree
            sumIndex = int(lower_bound(sums.begin(), sums.end(), sum) - sums.begin());
            int left = int(upper_bound(sums.begin(), sums.end(), sum - upper - 1) - sums.begin());
            int right = int(upper_bound(sums.begin(), sums.end(), sum - lower) - sums.begin());
            result += query(right) - query(left);
            //cout << "sumIndex: " << sumIndex << endl;
            //cout << "left: " << left << " : " << query(left) << endl;
            //cout << "right: " << right << " : " << query(right) << endl;
            update(n + 1, sumIndex + 1, 1);
        }
        return result;
    }
};
