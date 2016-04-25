//
//  278_First_Bad_Version.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/24/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <iostream>


// Forward declaration of isBadVersion API.
bool isBadVersion(int version){
    return (version >= 1702766719);
}

class Solution {
    //When 2 integer add together, notice for overflow!!!!
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        while(left < right){
            int middle = (int)(((long)left + (long)right) / 2);
            if(isBadVersion(middle)){
                right = middle;
            }else{
                left = middle + 1;
            }
        }
        return left;
    }
};


int main(){
    Solution ss;
    int n = 2126753390;
    std::cout << ss.firstBadVersion(n) << std::endl;
}