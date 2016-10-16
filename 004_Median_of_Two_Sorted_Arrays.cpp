//
//  004_Median_of_Two_Sorted_Arrays.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/13/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    int getKth(vector<int>& nums1, vector<int>& nums2, int m, int n, int k){
        //Kth is 0-based, change it to 1-based for easier computation
        k++;
        int left = max(0, k - n);
        int right = min(k, m);
        int mid = left + (right - left) / 2;
        //(mid) in here stands for the number of elements remain in the left part in nums1
        //After each cut, (mid) is the elements number remains in the left part in nums1
        //and (k-mid) is the elements number remains in the left part of nums2
        while(left <= right){
            mid = left + (right - left) / 2;
            if(mid > 0 && (k - mid) < n && nums1[mid - 1] > nums2[k - mid])
                right = mid - 1;
            else if(mid < m && (k - mid) > 0 && nums1[mid] < nums2[k - mid - 1])
                left = mid + 1;
            else{
                if(mid == 0)
                    return nums2[k - 1];
                if(k - mid == 0)
                    return nums1[k - 1];
                return max(nums1[mid - 1], nums2[k - mid - 1]);
            }
        }
        return max(nums1[mid - 1], nums2[k - mid - 1]);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = (int)nums1.size();
        int n = (int)nums2.size();
        return (getKth(nums1, nums2, m, n, (m + n - 1) / 2) + getKth(nums1, nums2, m, n, (m + n) / 2)) * 0.5;
    }
};


/*
int main(void){
    Solution ss;
    vector<int> nums1 = {1,3,5,7,9,2,5,7,3,6,8,2,3,6,8,2,3,5,7,22,47,3232,8};
    vector<int> nums2 = {7,6,9,2,5,8,22,6,9,3,8,32,5,9,3,2,88,52,4,2};
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int m = (int)nums1.size();
    int n = (int)nums2.size();
    for(int i = 0; i < m + n; ++i){
        cout << ss.getKth(nums1, nums2, m, n, i) << " ";
    }
    cout << endl;
    //cout << ss.findMedianSortedArrays(nums1, nums2) << endl;
}
*/
