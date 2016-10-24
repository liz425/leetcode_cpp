//
//  213_House_Robber_II.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/22/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    //break the solution into 2 cases: 1.Do not rob the first one.  2.Do not rob the last one.
    //Then use same DP solution, just change start / end point.
    //It's OK that those 2 cases have overlap (do not rob either one).
    //Corner case: if nums.size() == 1, both cases with skip the only house, which is wrong.. so just return that house.
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        int DP[2][2] = {{0, 0}, {0, 0}};
        //notice that 'nums.size()' is unsigned_int, if 'nums' is empty, then 'nums.size() - 1' is overflow rather than -1
        for(int i = 0; i < int(nums.size()) - 1; ++i){
            DP[0][(i + 2) % 2] = max(DP[0][(i + 1) % 2], DP[0][i % 2] + nums[i]);
        }
        for(int i = 1; i < int(nums.size()); ++i){
            DP[1][(i + 2) % 2] = max(DP[1][(i + 1) % 2], DP[1][i % 2] + nums[i]);
        }
        return max(DP[0][int(nums.size()) % 2], DP[1][int(nums.size() + 1) % 2]);
    }
};


/*
int main(void){
    Solution ss;
    vector<int> nums;
    cout << ss.rob(nums) << endl;
}
*/
