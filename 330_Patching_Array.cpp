//
//  330_Patching_Array.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/17/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
    //greedy. miss is the currently smallest number.
    //if the next num : nums[i] <= miss, then we could use it and expand miss --> miss + nums[i]
    //Otherwise, we need to choose from [1-miss] to fill the missing hole
    //Obviously, choose miss will have the highest profit, to expand miss --> miss * 2
    //Notice that there is a test case where n = 2147483647(INT_MAX), thus max should use long rather than int
public:
    int minPatches(vector<int>& nums, int n) {
        long miss = 1;
        int i = 0;
        int patch = 0;
        while(miss <= n){
            if(i < nums.size() && nums[i] <= miss){
                miss += nums[i++];
            }else{
                miss = miss << 1;
                patch++;
            }
        }
        return patch;
    }
};


class Solution {
    //Brutal force, MLE & TLE
private:
    int minPatch;
    void patchNum(vector<bool>& current, int j){
        int n = (int)current.size() - 1;
        for(int i = n; i >= 0; --i){
            //should go from n to 1 to avoid updating current[i] multi times: i + j, i + 2*j, i + 3*j
            //Otherwise, if the original is [true, false, false, ...],
            //after the loop its all true
            if(current[i] && i + j <= n){
                current[i + j] = true;
            }
        }
    }
    void DFS(int n, int lastMissing, vector<bool> current, int patchCnt){
        if(patchCnt > minPatch){
            return;
        }
        for(int i = lastMissing + 1; i <= n; ++i){
            if(!current[i]){    //found a new missing number
                for(int j = i; j >= 1; j--){
                    vector<bool> next = current;
                    patchNum(next, j);
                    DFS(n, i, next, patchCnt + 1);
                }
                return;     //found missing number, hence it's not a leaf level, should not update minPatch
            }
        }
        //now on leaves
        minPatch = min(minPatch, patchCnt);
        return;
    }
public:
    int minPatches(vector<int>& nums, int n) {
        minPatch = INT_MAX;
        vector<bool> current(long(n) + 1, false);
        current[0] = true;
        for(int num : nums){
            patchNum(current, num);
        }
        DFS(n, 0, current, 0);
        return minPatch;
    }
};


/*
int main(void){
    Solution ss;
    vector<int> nums = {1, 2, 31, 33};
    int n = 2147483647;
    cout << ss.minPatches(nums, n) << endl;
}
 */
