//
//  214_Shortest_Palindrome.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/8/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    //KMP, T = O(n), Space = O(n)
    vector<int> getNext(string P){
        int m = (int)P.size();
        vector<int> next(m + 1, -1);
        int k = -1;
        for(int i = 1; i <= m; ++i){
            while(k >= 0 && P[k] != P[i - 1]){
                k = next[k];
            }
            next[i] = ++k;
        }
        return next;
    }
public:
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        vector<int> next = getNext(s);
        int n = (int)s.size();
        int i = 1, k = 0;
        for(i = 1; i <= n; ++i){
            while(k >= 0 && s[k] != r[i - 1]){
                k = next[k];
            }
            k++;
        }
        string pre = s.substr(k, n - k);
        reverse(pre.begin(), pre.end());
        return pre + s;
    }
};

/*
int main(void){
    Solution ss;
    cout << ss.shortestPalindrome("aba") << endl;
}
*/
