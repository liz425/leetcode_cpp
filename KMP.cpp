//
//  KMP.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/7/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


//get next array
vector<int> getNext(string P){
    int m = (int)P.size();
    vector<int> next(m + 1, 0);
    next[0] = -1;
    //We have to initial k as -1, thus next[1] will always be 0
    //Otherwise, when k == 0 & i = 1, P[k] == P[i - 1], thus next[1] = 1
    //The insight here is that next[i] is the length of prefix which is a suffix of P[1..i], BUT should be smaller than i
    int k = -1;
    for(int i = 1; i <= m; ++i){
        while(k >= 0 && P[k] != P[i - 1]){
            k = next[k];
        }
        next[i] = ++k;
    }
    return next;
}

//match pattern within string T
vector<int> KMP_matcher(string P, string T){
    vector<int> result;
    if(P.empty())
        return result;
    vector<int> next = getNext(P);
    int k = 0;
    int m = (int)P.size();
    int n = (int)T.size();
    for(int i = 1; i <= n; ++i){
        while(k >= 0 && P[k] != T[i - 1]){
            k = next[k];
        }
        k++;
        if(k == m){
            result.push_back(i - m);    //index is 0 - based
            k = next[k];
        }
    }
    return result;
}

/*
int main(void){
    vector<int> result = KMP_matcher("aa", "aaa");
    for(int idx : result)
        cout << idx << endl;
}
*/
