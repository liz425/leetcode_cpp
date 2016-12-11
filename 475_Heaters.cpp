//
//  475_Heaters.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/10/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int m = (int)houses.size();
        int n = (int)heaters.size();
        int j = 0;
        int res = 0;
        for(int i = 0; i < m; ++i){
            if(j == n - 1){
                res = max(res, abs(houses[i] - heaters[j]));
            }else{
                if(abs(houses[i] - heaters[j]) < abs(houses[i] - heaters[j + 1])){
                    res = max(res, abs(houses[i] - heaters[j]));
                }else{
                    res = max(res, abs(houses[i] - heaters[j + 1]));
                    j++;
                }
            }
        }
        return res;
    }
};
