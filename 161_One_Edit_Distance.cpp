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
        int m = int(s.size()), n = int(t.size());
        if(abs(m - n) > 1)
            return false;
        else{
            int count = 0;
            for(int i = 0; i < min(m, n); ++i){
                if(s[i] != t[i]){
                    count++;
                    if(count >= 2)
                        return false;
                    if(m == n + 1)
                        s.erase(i--, 1);
                    else if(n == m + 1)
                        t.erase(i--, 1);
                }
            }
            return (count == 1 || s.size() != t.size());
        }
    }
};

/*
int main(){
    Solution ss;
    cout << ss.isOneEditDistance("ab", "cab");
    return 0;
}
*/