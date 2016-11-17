//
//  157_Read_N_Characters_Given_Read4.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/15/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        
        int k = n / 4 + ((n % 4)? 1 : 0);
        int cnt = 0;
        char read4Buf[4];
        for(int i = 0; i < k; ++i){
            int obtained = read4(read4Buf);
            for(int j = 0; j < obtained; ++j){
                buf[cnt + j] = read4Buf[j];
            }
            cnt += obtained;
            if(obtained < 4){
                break;
            }
        }
        return min(n, cnt);
    }
};
