//
//  016_3Sum_Closest.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 5/13/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
using namespace std;


class Solution2 {
    //time: O(n^2), space: O(1)
public:
    int threeSumClosest(vector<int>& nums, int target){
        sort(nums.begin(), nums.end());
        int len = (int)nums.size();
        int min_diff = INT_MAX;
        for(int mid = 1; mid < len - 1; ++mid){
            int remain = target - nums[mid];
            int left = 0, right = len - 1;
            while(left < mid && mid < right){
                int diff = nums[left] + nums[right] - remain;
                if(diff == 0){
                    return target;
                }else if(diff < 0){
                    ++left;
                }else{
                    --right;
                }
                if(abs(min_diff) > abs(diff)){
                    min_diff = diff;
                }
            }
        }
        return target + min_diff;
    }
};


class Solution {
    //time: O(n^3), space: O(1)
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = (int)nums.size();
        int deviation = INT_MAX;
        int sum = 0;
        for(int i = 0; i < len - 2; i++){
            for(int j = i + 1; j < len - 1; j++){
                for(int k = j + 1; k < len; k++){
                    long var = -(long(target) - nums[i] - nums[j] - nums[k]);
                    if(abs(var) < deviation){
                        sum = nums[i] + nums[j] + nums[k];
                        deviation = abs(target - sum);
                    }else if(var > deviation){
                        break;
                    }
                }
            }
        }
        return sum;
    }
};

/*
int main(){
    Solution2 ss;
    vector<int> nums = {43,75,-90,47,-49,72,17,-31,-68,-22,-21,-30,65,88,-75,23,97,-61,53,87,-3,33,20,51,-79,43,80,-9,34,-89,-7,93,43,55,-94,29,-32,-49,25,72,-6,35,53,63,6,-62,-96,-83,-73,66,-11,96,-90,-27,78,-51,79,35,-63,85,-82,-15,100,-82,1,-4,-41,-21,11,12,12,72,-82,-22,37,47,-18,61,60,55,22,-6,26,-60,-42,-92,68,45,-1,-26,5,-56,-1,73,92,-55,-20,-43,-56,-15,7,52,35,-90,63,41,-55,-58,46,-84,-92,17,-66,-23,96,-19,-44,77,67,-47,-48,99,51,-25,19,0,-13,-88,-10,-67,14,7,89,-69,-83,86,-70,-66,-38,-50,66,0,-67,-91,-65,83,42,70,-6,52,-21,-86,-87,-44,8,49,-76,86,-3,87,-32,81,-58,37,-55,19,-26,66,-89,-70,-69,37,0,19,-65,38,7,3,1,-96,96,-65,-52,66,5,-3,-87,-16,-96,57,-74,91,46,-79,0,-69,55,49,-96,80,83,73,56,22,58,-44,-40,-45,95,99,-97,-22,-33,-92,-51,62,20,70,90};
    int target = 284;
    clock_t start, end;
    start = clock();
    cout << ss.threeSumClosest(nums, target) << endl;
    end = clock();
    double time_consumed = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    cout << time_consumed << endl;
}
*/