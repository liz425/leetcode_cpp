//
//  351_Android_Unlock_Patterns.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/17/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    //another optimization is that, using symmetry, only case 1, 3, 7, 9 are the same
    //case 2, 4, 6, 8 are the same;
    //thus only need to computer case 1 , 2 and 5,
    //result = case_1 * 4 + case_2 * 4 + case_5
    int numberOfPatterns(int m, int n) {
        return DFS(m, n, 1, 1, 0, 0);
    }
    int DFS(int m, int n, int x, int y, int marked, int cnt){
        if(cnt >= n)
            return 1;
        int result = (cnt < m)? 0 : 1;
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                int newMark = marked | (1 << (i * 3 + j));
                int midX = x + i, midY = y + j;
                if(newMark != marked && (midX % 2 || midY % 2 || (newMark >> (midX / 2 * 3 + midY / 2)) & 0x1)){
                    result += DFS(m, n, i, j, newMark, cnt + 1);
                }
            }
        }
        return result;
    }
};
