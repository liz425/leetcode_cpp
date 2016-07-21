//
//  367_Valid_Perfect_Square.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 7/18/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution{
    //Taking care of multiplication overflow
public:
    bool isPerfectSquare(int num){
        if(num == 1) return true;
        if(num == 2 || num == 3) return false;
        int low = 1, high = num / 2;
        int mid = (low + high) / 2;
        while(low <= high){
            long product = long(mid) * long(mid);
            if(product == num){
                return true;
            }else if(product < num){
                low = mid + 1;
                mid = (low + high) / 2;
            }else{
                high = mid - 1;
                mid = (low + high) / 2;
            }
        }
        return false;
    }
};

/*
int main(){
    Solution ss;
    cout << ss.isPerfectSquare(808201) << endl;
}
*/