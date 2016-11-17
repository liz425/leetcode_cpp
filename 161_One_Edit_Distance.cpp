//
//  161_One_Edit_Distance.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 8/31/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = (int)s.size();
        int n = (int)t.size();
        if(abs(m - n) > 1)
            return false;
        int count = 0;
        for(int i = 0; i < min(m, n); ++i){
            if(s[i] != t[i]){
                if(++count > 1)
                    return false;
                //Since the length variance is at most 1
                //When meet unmatch, we should make sure that after correction, the length should be the same
                //Otherwise, due to the unmatch length, we would have at least one more match later
                if(m == n + 1){
                    s.erase(i--, 1);
                }else if(n == m + 1){
                    t.erase(i--, 1);
                }
            }
        }
        //if count == 1, then the current length match
        //otherwise, the unmatch must exist in the last char
        return (count == 1 || s.size() != t.size());
    }
};

/*
 int main(){
 Solution ss;
    cout << ss.isOneEditDistance("ab", "cab");
    return 0;
}
*/
