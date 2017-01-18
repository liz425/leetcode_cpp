//
//  292_Nime_Game.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 2/7/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"



class Solution {
public:
    bool canWinNim(int n) {
        return (n % 4 != 0);
    }
};
