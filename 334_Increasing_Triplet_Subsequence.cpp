//
//  334_Increasing_Triplet_Subsequence.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 7/21/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    //Time: O(n), Space: O(1)
    //Assume that [AA, BB, CC] is the first triplet we encountered, then AA must be the smallest item
    //seen so far(within all the nums before AA).
    //Prove: If there exist a number DD before AA and DD < AA, then [DD, BB, CC] will form a triplet,
    //violating our assumption.
    //Then according to our algo, it will assign AA to c1.
    //----------------------------------------------------
    //Deduction2: nums between AA and BB must be larger than BB.
    //Prove: first, all of those nums are larger than AA, otherwise AA will be assign to a new number.
    //If one of those nums EE is small than BB, then [AA, EE, BB] will form a triplet.
    //Accord to our algo, BB will be assigned to c2.
    //-------------------
    //At last, as long as there is a CC larger than BB, our algo will return true.
public:
    bool increasingTriplet(vector<int>& nums) {
        int c1 = INT_MAX, c2 = INT_MAX;
        for (int x : nums) {
            if (x <= c1) {
                c1 = x;           // c1 is min seen so far (it's a candidate for 1st element)
            } else if (x <= c2) { // here when x > c1, i.e. x might be either c2 or c3
                c2 = x;           // x is better than the current c2, store it
            } else {              // here when we have/had c1 < c2 already and x > c2
                return true;      // the increasing subsequence of 3 elements exists
            }
        }
        return false;
    }
};