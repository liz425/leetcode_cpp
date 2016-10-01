//
//  275_H-Index_II.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 5/31/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;
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



