//
//  467_Unique_Substrings_in_Wraparound_String.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/3/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"



class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int n = (int)p.size();
        int left = 0, right = 0;
        vector<int> cnt(26, 0);
        while(left < n){
            for(right = left + 1; right < n; right++){
                if(right == 0 || p[right] - 'a' == (p[right - 1] - 'a' + 1) % 26){
                    continue;
                }else{
                    break;
                }
            }
            for(int i = left; i < min(right, left + 26); ++i){
                cnt[p[i] - 'a'] = max(cnt[p[i] - 'a'], right - i);
            }
            left = right;
        }
        int sum = 0;
        for(int i = 0; i < 26; i++){
            sum += cnt[i];
        }
        return sum;
    }
};


/*
int main(void){
    Solution ss;
    string p = "";
    cout << ss.findSubstringInWraproundString(p) << endl;
}
*/
