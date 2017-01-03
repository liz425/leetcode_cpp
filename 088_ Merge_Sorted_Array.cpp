//
//  088_ Merge_Sorted_Array.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/16/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution2 {
    //T = O(m + n), in-place
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(m > 0 || n > 0){
            if(m <= 0){
                nums1[m + n - 1] = nums2[n - 1];
                n--;
            }else if(n <= 0){
                nums1[m + n - 1] = nums1[m - 1];
                m--;
            }else if(nums1[m - 1] < nums2[n - 1]){
                nums1[m + n - 1] = nums2[n - 1];
                n--;
            }else{
                nums1[m + n - 1] = nums1[m - 1];
                m--;
            }
        }
    }
};


class Solution {
    //T = O(m + n), in-place
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(m > 0 && n > 0){
            if(nums1[m - 1] > nums2[n - 1]){
                nums1[m + n - 1] = nums1[m - 1];
                m--;
            }else{
                nums1[m + n - 1] = nums2[n - 1];
                n--;
            }
        }
        while(n > 0){
            nums1[n - 1] = nums2[n - 1];
            n--;
        }
    }
};

/*
 int main(){
    Solution ss;
    vector<int> nums1 = {1,4,5,7,8,8,9,0,0,0,0,0,0};
    int m = 7;
    vector<int> nums2 = {2,3,4,4,9,10};
    int n = 6;
    ss.merge(nums1, m, nums2, n);
    for(int i = 0; i < m + n; i++){
        cout << nums1[i] << endl;
    }
}
*/
