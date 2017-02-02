//
//  480_Sliding_Window_Median.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 1/25/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
    //T = O(n*logk), use one multiset as a heap. Maintain mid iterator.
    //Keep mid pointer to the "k/2"-th element in the window.
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2);
        vector<double> medians;
        medians.push_back((double(*mid) + *next(mid, k % 2 - 1)) / 2);
        for(int i = k; i < nums.size(); ++i){
            window.insert(nums[i]);
            //"in C++11, newly inserted elements follow their equivalents already in the container."
            //Thus, when nums[i] == *mid, we do not need to decrease mid, since nums[i] will inserted after mid.
            if(nums[i] < *mid){
                mid--;
            }
            if(nums[i - k] <= *mid ){
                mid++;
            }
            window.erase(window.lower_bound(nums[i - k]));
            //In case of addition overflow, we need to first converted to double, then add them up
            medians.push_back((double(*mid) + *next(mid, k % 2 - 1)) / 2);
        }
        return medians;
    }
};



class Solution {
    //Using multiset as HashHeap
    //addNum: O(logk),  removeNum: O(logk)
    //getMedian: O(1),  medianSlidingWindow: O(n*logk)
    multiset<int, std::less<int>> minHeap;
    multiset<int, std::greater<int>> maxHeap;
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = (int)nums.size();
        vector<double> result;
        for(int i = 0; i < n; ++i){
            insertNum(nums[i]);
            if(minHeap.size() + maxHeap.size() > k){
                deleteNum(nums[i - k]);
            }
            if(minHeap.size() + maxHeap.size() == k){
                result.push_back(getMedian(k));
            }
        }
        return result;
    }
    void insertNum(int num){
        int m = (int)maxHeap.size();
        int n = (int)minHeap.size();
        if(m == n){
            if(!minHeap.empty() && num > *(minHeap.begin())){
                maxHeap.insert(*(minHeap.begin()));
                minHeap.erase(minHeap.begin());
                minHeap.insert(num);
            }else{
                maxHeap.insert(num);
            }
        }else{
            if(!maxHeap.empty() && num < *(maxHeap.begin())){
                minHeap.insert(*(maxHeap.begin()));
                maxHeap.erase(maxHeap.begin());
                maxHeap.insert(num);
            }else{
                minHeap.insert(num);
            }
        }
    }
    void deleteNum(int num){
        //Notice that to remove an item from multiset, we should use .erase(iterator) rather than .erase(val)
        //The reason is that since multiset can contain duplicate nums, .erase(val) will remove all num with the same value, NOT the first one.
        //.erase(iterator) will only remove the designated one, which is all we need
        if(maxHeap.count(num)){
            maxHeap.erase(maxHeap.find(num));
        }else{
            minHeap.erase(minHeap.find(num));
        }
        if(maxHeap.size() < minHeap.size()){
            maxHeap.insert(*(minHeap.begin()));
            minHeap.erase(minHeap.begin());
        }else if(maxHeap.size() > minHeap.size() + 1){
            minHeap.insert(*(maxHeap.begin()));
            maxHeap.erase(maxHeap.begin());
        }
    }
    double getMedian(int k){
        //If hi = INT_MAX, lo = INT_MAX - 1, then mid = (lo + hi) / 2 will overflow.
        //If hi = INT_MAX, lo = INT_MIN, then mid = lo + (hi - lo) / 2 will ALSO overflow.
        //Thus the best way to get rid of overflow is to convert int to long or double.
        if(k % 2){
            return *(maxHeap.begin());
        }else{
            return (double(*(minHeap.begin())) + double(*(maxHeap.begin()))) / 2.0;
        }
    }
};


/*
int main(void){
    Solution ss;
    vector<int> nums = {1,2,3,4,2,3,1,4,2};
    vector<double> out = ss.medianSlidingWindow(nums, 3);
    for(int num : out){
        cout << num << endl;
    }
}
*/
