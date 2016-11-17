//
//  277_Find_the_Celebrity.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/15/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
    //Every comparison will exclude one candidate as follows:
    //if a knows b, exclude a
    //if a do not know b, exlude b
    //Thus through n - 1 times of comparions, we can exclude n - 1 ones, and only left one possible candidate
    //then verify it. Kind of similar to bubble sort
public:
    int findCelebrity(int n) {
        int candid = 0;     //set 0 as current candid
        int preOneKnowsCandid = -1;
        for(int i = 1; i < n; i++){
            if(knows(candid, i)){
                preOneKnowsCandid = candid;
                candid = i;     //at least we know that 'preOneKnowsCandid' knows 'candid'
            }
        }
        //Now, we already got the info that candid does not know anyone after candid,
        //So we only need to check if candid know i which is smaller than candid. save some comparisons
        for(int i = 0; i < candid; ++i){
            if(knows(candid, i)){
                return -1;
            }
        }
        for(int i = 0; i < n; ++i){
            if(i != candid && i != preOneKnowsCandid && !knows(i, candid)){
                return -1;
            }
        }
        return candid;
    }
};
