//
//  223_Rectangle_Area.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/16/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <algorithm>
//min(), max() are defined in algorithm
using namespace std;

class Solution {
    //Be careful that min(C, G) - max(A, E) may overflow, so use the following instead;
    //min(C, G) - min(max(A, E), min(C, G))
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        return (C - A) * (D - B) - (min(C, G) - min(max(A, E), min(C, G))) * (min(D, H) - min(max(B, F), min(D, H))) + (G - E) * (H - F);
    }
};