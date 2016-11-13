//
//  275_H-Index_II.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 5/31/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
public:
    int hIndex(vector<int>& citations) {
        int left = 0;
        int size = (int)citations.size();
        int right = size + 1;
        //Now 1 <= mid <= size, and 0 <= left <= size
        //Initial: left == 0. We then only test mid, and assign all valid mid to left
        //Thus finally we need only return left
        while(left + 1 < right){
            int mid = left + (right - left) / 2;
            if(citations[size - mid] >= mid)
                left = mid;
            else
                right = mid;
        }
        return left;
    }
};



class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = (int)citations.size();
        int left = -1;
        int right = size;
        while(right - left > 1){
            int mid = (left + right) / 2;
            if(citations[mid] >= size - mid){
                right = mid;
            }else{
                left = mid;
            }
        }
        return size - right;
    }
};



