//
//  Lint_Sliding_Window_Median.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/15/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    //Using multiset as HashHeap
    //addNum: O(logk),  removeNum: O(logk)
    //getMedian: O(1),  medianSlidingWindow: O(n*logk)
public:
    multiset<int> minHeap;
    multiset<int, std::greater<int>> maxHeap;
    void addNum(int num){
        if(maxHeap.size() == minHeap.size()){
            if(minHeap.empty() || *(minHeap.begin()) >= num){
                maxHeap.insert(num);
                //cout << "insert to maxHeap" << endl;
            }else{
                maxHeap.insert(*(minHeap.begin()));
                minHeap.erase(minHeap.begin());
                minHeap.insert(num);
                //cout << "insert to minHeap, swap" << endl;
            }
        }else{
            if(!maxHeap.empty() && *(maxHeap.begin()) <= num){
                minHeap.insert(num);
                //cout << "insert to minHeap" << endl;
            }else{
                minHeap.insert(*(maxHeap.begin()));
                maxHeap.erase(maxHeap.begin());
                maxHeap.insert(num);
                //cout << "insert to maxHeap, swap" << endl;
            }
        }
    }
    void removeNum(int num){
        auto maxIt = maxHeap.find(num);
        if(maxIt != maxHeap.end()){
            //cout << "removing: " << *(maxIt) << endl;
            maxHeap.erase(maxIt);
        }else{
            auto minIt = minHeap.find(num);
            if(minIt != minHeap.end()){
                //cout << "removing: " << *(minIt) << endl;
                minHeap.erase(minIt);
            }
        }
        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.insert(*(maxHeap.begin()));
            maxHeap.erase(maxHeap.begin());
        }else if(maxHeap.size() < minHeap.size()){
            maxHeap.insert(*(minHeap.begin()));
            minHeap.erase(minHeap.begin());
        }
    }
    int getMedian(){
        return *(maxHeap.begin());
    }
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        vector<int> result;
        for(int i = 0; i < nums.size(); ++i){
            addNum(nums[i]);
            if(i >= k)
                removeNum(nums[i - k]);
            if(i >= k - 1)
                result.push_back(getMedian());
        }
        return result;
    }
};

/*
int main(void){
    Solution ss;
    vector<int> nums = {1,2,7,7,2};
    vector<int> out = ss.medianSlidingWindow(nums, 3);
    for(int num : out){
        cout << num << endl;
    }
}
*/
