//
//  Leetcode_Contest4.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/3/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

/*
class Solution2 {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int len1 = (int)s1.size();
        int len2 = (int)s2.size();
        vector<int> index(len1, -1);
        vector<int> times(len1, 0);
        //if s2 has char which is not contained in s1, return 0
        unordered_set<char> distinct(s1.begin(), s1.end());
        for(char ch : s2){
            if(distinct.count(ch) == 0){
                return 0;
            }
        }
        int i = 0;
        while(index[i] == -1){
            int k = i - 1;
            for(int j = 0; j < len2; ++j){
                do{
                    if(k == len1 - 1){
                        times[i]++;
                    }
                    k = (k + 1) % len1;
                }while(s1[k] != s2[j]);
            }
            index[i] = k;
            i = (k + 1) % len1;
        }
        cout << i << endl;
        int div1 = 0, div2 = 0;
        int k = i;
        do{
            div2++;
            div1 += times[k];
            k = (index[k] + 1) % len1;
            if(k == 0){
                div1++;
            }
        }while(k != i);
        //s1 * div1 can be partitioned into s2 * div2
        cout << div1 << endl;
        cout << div2 << endl;
        int idx = 0;
        int cnt = 0;
        while(n1 > 0){
            n1 -= times[idx];
            if(n1 > 0){
                cnt++;
            }else{
                break;
            }
            idx = (index[idx] + 1) % len1;
            if(idx == 0){
                n1--;
            }
        }
        return cnt / n2;
    }
};
*/



class Solution {
    //Correct, but TLE
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int len1 = (int)s1.size();
        int len2 = (int)s2.size();
        vector<int> index(len1, 0);
        vector<int> times(len1, 0);
        //if s2 has char which is not contained in s1, return 0
        unordered_set<char> distinct(s1.begin(), s1.end());
        for(char ch : s2){
            if(distinct.count(ch) == 0){
                return 0;
            }
        }
        for(int i = 0; i < len1; ++i){
            int k = i - 1;
            for(int j = 0; j < len2; ++j){
                do{
                    if(k == len1 - 1){
                        times[i]++;
                    }
                    k = (k + 1) % len1;
                }while(s1[k] != s2[j]);
            }
            index[i] = k;
        }
        int idx = 0;
        int cnt = 0;
        while(n1 > 0){
            n1 -= times[idx];
            if(n1 > 0){
                cnt++;
            }else{
                break;
            }
            idx = (index[idx] + 1) % len1;
            if(idx == 0){
                n1--;
            }
        }
        return cnt / n2;
    }
};

/*
int main(void){
    Solution2 ss;
    string s1 = "abcd";
    string s2 = "abcd";
    int n1 = 1000000, n2 = 1000000;
    cout << ss.getMaxRepetitions(s1, n1, s2, n2) << endl;
}
*/
