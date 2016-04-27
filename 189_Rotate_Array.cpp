//
//  189_Rotate_Array.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/26/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;


class Solution2 {
    //3 Rotations
public:
    void rotate(vector<int>& nums, int k) {
        k = k % (int)nums.size();
        reverse(nums.begin(), nums.end() - k);
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};



class Solution {
    //The Juggling algorithm
public:
    int GreatestCommonDivisor(int a, int b){
        if(a < b){
            swap(a, b);
        }
        while(b != 0){
            a = a % b;
            swap(a, b);
        }
        return a;
    }
    void rotate(vector<int>& nums, int k) {
        int len = (int)nums.size();
        int d = GreatestCommonDivisor(len, k);
        int n = len / d;
        for(int j = 0; j < d; j++){
            int p = j;
            int tmp = nums[p];
            for(int i = 0; i < n; i++){
                swap(nums[(p + k) % len], tmp);
                p = (p + k) % len;
            }
        }
    }
};


int main(){
    Solution ss;
    vector<int> nums = {1,2,3,4,5,6};
    ss.rotate(nums, 2);
    int a = 0;
}