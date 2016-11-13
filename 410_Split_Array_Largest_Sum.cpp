//
//  410_Split_Array_Largest_Sum.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/31/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution2 {
    //T = O(N*logN), N = nums size
    //Binary serach, maxSum located in the range [maxNum, numSum]
    //Just binary search this range to get the smallest availabe subSum
    //Greedy used here: if cnt number of segments could contain all this sum, then more container also can.
    //Similar to the problem: if I have m bottle with size maxSum, can we put N stones (continuously) in these bottles
public:
    int splitArray(vector<int>& nums, int m) {
        int maxNum = 0, sum = 0;
        for(int num : nums){
            sum += num;
            maxNum = max(maxNum, num);
        }
        int left = maxNum, right = sum;
        while(left < right - 1){
            int mid = left + (right - left) / 2;
            if(splitable(nums, m, mid)){
                right = mid;
            }else{
                left = mid;
            }
        }
        if(splitable(nums, m, left))
            return left;
        else
            return right;
    }
    bool splitable(vector<int>& nums, int m, int maxSum){
        int cnt = 0;
        int sum = 0;
        for(int num : nums){
            if(sum + num <= maxSum){
                sum += num;
                continue;
            }else{
                cnt++;
                sum = num;
                if(cnt >= m)
                    return false;
            }
        }
        return cnt + 1 <= m;    //should cnt the last one more
    }
};


class Solution {
    //DFS solution, TLE!!!!!!!
    //T = (2^N)
private:
    int minSum;
public:
    int splitArray(vector<int>& nums, int m) {
        if(nums.empty() || m == 0)
            return 0;
        int sum = 0, maxElem = 0;
        for(int num : nums){
            sum += num;
            maxElem = max(maxElem, num);
        }
        minSum = INT_MAX;
        int maxSum = max(maxElem, sum / m);
        vector<int> partition;
        DFS(nums, m, partition, maxSum);
        return minSum;
    }
    void DFS(vector<int>& nums, int m, vector<int>& partition, int maxSum){
        int remain = m - (int)partition.size();
        int start = partition.empty()? 0 : start = partition.back() + 1;
        if(remain == 1){
            maxSum = max(maxSum, accumulate(nums.begin() + start, nums.end(), 0));
            minSum = min(minSum, maxSum);
            return;
        }
        int sum = 0;
        for(int i = start; i <= (int)nums.size() - remain; ++i){
            sum += nums[i];
            if(sum >= minSum)
                return;
            if(i < (int)nums.size() - remain && sum + nums[i + 1] <= maxSum)
                continue;
            partition.push_back(i);
            DFS(nums, m, partition, max(maxSum, sum));
            partition.pop_back();
        }
    }
};

