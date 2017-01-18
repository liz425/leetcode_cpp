//
//  209_Minimum_Size_Subarray_Sum.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/13/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution3 {
    //T = O(n*logn). Make sum[] first, then binary search
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = (int)nums.size();
        if(n == 0){
            return 0;
        }
        vector<int> sum(n + 1, 0);
        for(int i = 1 ; i <= n; ++i){
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        int minLen = INT_MAX;
        //sum is an increasing array (sorted), thus we can use lower_bound
        for(auto it = sum.begin(); it < sum.end(); it++){
            auto tail = lower_bound(sum.begin(), sum.end(), *it + s);
            //if could not find such an sum, then tail will be sum.end(), the length should be invalid
            if(tail != sum.end()){
                minLen = min(minLen, int(tail - it));
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};



class Solution2 {
    //T = O(n). Two pointers
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = (int)nums.size();
        if(n == 0){
            return 0;
        }
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int sum = nums[0];
        while(right < n){
            if(sum >= s){
                minLen = min(minLen, right - left + 1);
                sum -= nums[left++];
            }else{
                sum += nums[++right];
            }
        }
        return minLen == INT_MAX? 0 : minLen;
    }
};



class Solution {
    //T = O(n), Two pointers
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = (int)nums.size(), start = 0, sum = 0, minlen = INT_MAX;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            while (sum >= s) {
                //note here has an assumption: s > 0, which is given by the description,
                //otherwise when sum == 0, still go into the loop, and nums[start++] may out of index
                minlen = min(minlen, i - start + 1);
                sum -= nums[start++];
            }
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};
