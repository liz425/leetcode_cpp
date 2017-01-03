//
//  398_Random_Pick_Index.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/14/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    //Reservoir sampling
    //pick = O(n)
private:
    vector<int> _nums;
public:
    Solution(vector<int> nums):_nums(nums) {
        srand((unsigned int)time(NULL));
    }
    
    int pick(int target) {
        int cnt = 0;
        int index = 0;
        for(int i = 0; i < (int)_nums.size(); ++i){
            if(_nums[i] == target){
                cnt++;
                if(rand() % cnt == 0){
                    index = i;
                }
            }
        }
        return index;
    }
};


/*
int main(void){
    vector<int> nums = {1, 2, 3, 3, 3};
    int target = 3;
    Solution ss(nums);
    cout << ss.pick(target) << endl;
}
*/
