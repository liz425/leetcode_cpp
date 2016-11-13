//
//  321_Create_Maximum_Number.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/12/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
    //Use some trick in merge(), compare whether the following num is larger or equal to the first one
    //But only adopt the monotonically increasing sub-sequence
public:
    vector<int> pickNums(vector<int>& nums, int k){
        int size = (int)nums.size();
        deque<int> decrease;
        int n = size - k;   //pick k, remove size - k
        for(int i = 0; i < size; ++i){
            while(!decrease.empty() && n > 0 && nums[i] > decrease.back()){
                decrease.pop_back();
                n--;
            }
            decrease.push_back(nums[i]);
        }
        vector<int> result;
        while(k-- > 0){
            result.push_back(decrease.front());
            decrease.pop_front();
        }
        return result;
    }
    bool isGreater(vector<int>& nums1, vector<int>& nums2){
        int minSize = min((int)nums1.size(), (int)nums2.size());
        for(int i = 0; i < minSize; ++i){
            if(nums1[i] > nums2[i]){
                return true;
            }else if(nums1[i] < nums2[i]){
                return false;
            }
        }
        return nums1.size() >= nums2.size();
    }
    vector<int> merge(vector<int>& nums1, vector<int>& nums2){
        int m = (int)nums1.size();
        int n = (int)nums2.size();
        int i = 0, j = 0;
        vector<int> result;
        while(i < m && j < n){
            if(nums1[i] > nums2[j]){
                result.push_back(nums1[i]);
                i++;
            }else if(nums1[i] < nums2[j]){
                result.push_back(nums2[j]);
                j++;
            }else{
                int k = 1;
                while(i + k < m && j + k < n && nums1[i + k] == nums2[j + k] && nums1[i + k] >= nums1[i]){
                    k++;
                }
                if((i + k == m && j + k <  n && nums1[i] > nums2[j + k]) ||
                   (i + k <  m && j + k == n && nums1[i + k] >= nums2[j]) ||
                   (i + k <  m && j + k <  n && nums1[i + k] > nums2[j + k])){
                    for(int p = 0; p < k; p++){
                        if(p == 0 || nums1[i] >= nums1[i - 1]){
                            result.push_back(nums1[i++]);
                        }else{
                            break;
                        }
                    }
                }else{
                    for(int p = 0; p < k; p++){
                        if(p == 0 || nums2[j] >= nums2[j - 1]){
                            result.push_back(nums2[j++]);
                        }else{
                            break;
                        }
                    }
                }
            }
        }
        if(i < m){
            result.insert(result.end(), nums1.begin() + i, nums1.end());
        }
        if(j < n){
            result.insert(result.end(), nums2.begin() + j, nums2.end());
        }
        return result;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = (int)nums1.size();
        int len2 = (int)nums2.size();
        vector<int> result(k, 0);
        for(int i = max(0, k - len2); i <= min(len1, k); ++i){
            //choose i num from num1, (k - 1) num from nums2
            vector<int> candids1 = pickNums(nums1, i);
            vector<int> candids2 = pickNums(nums2, k - i);
            vector<int> combined = merge(candids1, candids2);
            if(isGreater(combined, result)){
                result = combined;
            }
        }
        return result;
    }
};




class Solution {
public:
    vector<int> pickNums(vector<int>& nums, int k){
        int size = (int)nums.size();
        deque<int> decrease;
        int n = size - k;   //pick k, remove size - k
        for(int i = 0; i < size; ++i){
            while(!decrease.empty() && n > 0 && nums[i] > decrease.back()){
                decrease.pop_back();
                n--;
            }
            decrease.push_back(nums[i]);
        }
        vector<int> result;
        while(k-- > 0){
            result.push_back(decrease.front());
            decrease.pop_front();
        }
        return result;
    }
    bool isGreater(vector<int>& nums1, vector<int>& nums2){
        int minSize = min((int)nums1.size(), (int)nums2.size());
        for(int i = 0; i < minSize; ++i){
            if(nums1[i] > nums2[i]){
                return true;
            }else if(nums1[i] < nums2[i]){
                return false;
            }
        }
        return nums1.size() >= nums2.size();
    }
    vector<int> merge(vector<int>& nums1, vector<int>& nums2){
        int m = (int)nums1.size();
        int n = (int)nums2.size();
        int i = 0, j = 0;
        vector<int> result;
        while(i < m && j < n){
            vector<int> part1(nums1.begin() + i, nums1.end());
            vector<int> part2(nums2.begin() + j, nums2.end());
            if(isGreater(part1, part2)){
                result.push_back(nums1[i++]);
            }else{
                result.push_back(nums2[j++]);
            }
        }
        if(i < m){
            result.insert(result.end(), nums1.begin() + i, nums1.end());
        }
        if(j < n){
            result.insert(result.end(), nums2.begin() + j, nums2.end());
        }
        return result;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = (int)nums1.size();
        int len2 = (int)nums2.size();
        vector<int> result(k, 0);
        for(int i = max(0, k - len2); i <= min(len1, k); ++i){
            //choose i num from num1, (k - 1) num from nums2
            vector<int> candids1 = pickNums(nums1, i);
            vector<int> candids2 = pickNums(nums2, k - i);
            vector<int> combined = merge(candids1, candids2);
            if(isGreater(combined, result)){
                result = combined;
            }
        }
        return result;
    }
};


/*
int main(void){
    Solution ss;
    vector<int> nums1 = {2,1,2,1,2,2,1,2,2,1,1,2,1,0,2,0,1,0,1,1,2,0,0,2,2,2,2,1,1,1,2,1,2,0,2,0,1,1,0,1,0,2,0,1,0,2,0,1,1,0,0,2,0,1,1,2,0,2,2,1,2,1,2,1,0,1,2,0,2,1,2,2,2,0,1,1,0,2,0,1,1,0,0,0,2,1,1,1,0,1,1,0,1,2,1,2,0,0,0,2,1,2,2,1,1,0,1,1,0,0,1,0,0,0,2,1,1,0,2,0,2,2,0,2,0,0,2,0,1,2,1,1,1,2,1,0,1,1,0,2,1,2,2,1,0,1,1,1,2,0,2,2,2,0,2,1,1,2,1,1,2,0,2,1,0,2,0,0,2,2,2,0,2,1,2,2,1,2,1,2,2,2,1,1,2,0,2,0,0,2,2,2,0,2,2,1,0,0,2,2,2,1,1,0,2,1,0,1,2,1,1,2,2,1,1,0,2,1,2,2,1,2,1,0,0,0,0,1,1,0,2,2,2,2,2,2,2,2,1,1,0,2,1,0,0,0,0,2,1,1};
    vector<int> nums2 = {1,1,0,2,0,1,1,1,0,2,2,2,1,1,0,1,2,1,2,1,0,1,2,2,2,2,1,1,0,2,0,1,0,0,1,1,0,1,2,1,2,1,2,0,1,1,1,1,2,0,1,1,1,0,0,1,0,1,2,1,1,0,2,2,1,2,0,2,0,1,1,2,0,1,1,2,2,1,0,1,2,2,0,1,1,2,2,0,2,2,0,2,1,0,0,2,1,0,0,2,1,2,1,2,0,2,0,1,1,2,1,1,1,2,0,2,2,0,2,2,0,2,1,2,1,2,0,2,0,0,1,2,2,2,2,1,2,2,0,1,0,0,2,2,2,2,0,1,0,2,1,2,2,2,1,1,1,1,2,0,0,1,0,0,2,2,1,0,0,1,1,0,0,1,1,0,2,2,2,2,2,1,0,2,2,0,0,1,0,0,1,1,1,2,2,0,0,2,0,0,0,1,2,0,2,0,1,2,0,1,2,0,1,1,0,0,1,2,1,0,2,1,0,1,2,0,1,1,2,1,0,2,1,2,1,1,0,2,2,1,0,2,1,1,1,0,0,0,1,0};
    int k = 500;
    cout << nums1.size() << endl;
    cout << nums2.size() << endl;
    vector<int> result = ss.maxNumber(nums1, nums2, k);
    for(int i = 0; i < (int)result.size(); ++i){
        cout << result[i] << endl;
    }
}
*/
