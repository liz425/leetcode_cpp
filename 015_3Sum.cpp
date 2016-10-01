//
//  015_3Sum.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 6/30/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
public:
    //Two pointer, faster and more concise.
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result = {};
        if(nums.size() < 3)
            return result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; ++i){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            int j = i + 1, k = (int)nums.size() - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0)
                    j++;
                else if(sum > 0)
                    k--;
                else{
                    result.push_back({nums[i], nums[j], nums[k]});
                    do{
                        j++;
                    }while(j < k && nums[j] == nums[j-1]);
                }
            }
        }
        return result;
    }
};


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> noDulp;
        unordered_map<int, int> map;
        for(int& num : nums){
            if(map[num]++ == 0){
                noDulp.push_back(num);
            }
        }
        sort(noDulp.begin(), noDulp.end());
        int size = (int)noDulp.size();
        vector<vector<int>> result;
        for(int i = 0; i < size; ++i){
            if(noDulp[i] > 0){
                break;
            }
            for(int j = i; j < size; ++j){
                if(noDulp[i] + noDulp[j] > 0){
                    break;
                }else if(-(noDulp[i] + noDulp[j]) < noDulp[j]){
                    break;
                }else{
                    if(map[-(noDulp[i] + noDulp[j])] == 0){
                        continue;
                    }
                    int cnt = 1;
                    if(i == j){
                        cnt++;
                    }
                    if(-(noDulp[i] + noDulp[j]) == noDulp[j]){
                        cnt++;
                    }
                    if(map[noDulp[j]] >= cnt){
                        vector<int> solution = {noDulp[i], noDulp[j], -(noDulp[i] + noDulp[j])};
                        result.push_back(solution);
                    }
                }
            }
        }
        return result;
    }
};

/*
int main(){
    Solution ss;
    vector<int> nums = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    ss.threeSum(nums);
}
*/
