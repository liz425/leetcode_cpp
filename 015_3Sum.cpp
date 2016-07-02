//
//  015_3Sum.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 6/30/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


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