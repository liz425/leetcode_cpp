//
//  434_Number_of_Segments_in_a_String.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/3/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"



class Solution {
public:
    int countSegments(string s) {
        int n = (int)s.size();
        int cnt = 0;
        bool preIsSpace = true;
        for(int i = 0; i < n; ++i){
            if(s[i] == ' '){
                preIsSpace = true;
                continue;
            }else if(i == 0 || preIsSpace){
                cnt++;
                preIsSpace = false;
            }
        }
        return cnt;
    }
};


/*
int main(void){
    Solution ss;
    cout << ss.countSegments("       ") << endl;
}
*/
