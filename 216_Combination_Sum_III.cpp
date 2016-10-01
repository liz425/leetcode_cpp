//
//  216_Combination_Sum_III.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 3/22/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void Sum3Helper(vector<int> sub, vector<vector<int>>& rtn, int k, int index, int remainSum){
        if(remainSum == 0 && k == 0){
            rtn.push_back(sub);
            return;
        }else if((9 - index + 1 < k) || ((9 + 9 - k + 1) * k / 2 < remainSum) || (index > remainSum)){
            return;
        }else{
            for(int i = index; i <= 9 - k + 1; i++){
                if(i > remainSum)
                    break;
                vector<int> tmp = sub;
                tmp.push_back(i);
                Sum3Helper(tmp, rtn, k - 1, i + 1, remainSum - i);
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> rtn;
        vector<int> empty;
        Sum3Helper(empty, rtn, k, 1, n);
        return rtn;
    }
};


//int main(void){
//    Solution sol;
//    int k = 3;
//    int n = 9;
//    vector<vector<int>> ans = sol.combinationSum3(k, n);
//    for(int i = 0; i < ans.size(); i++){
//        cout << "[" ;
//        for(int j = 0; j < ans[i].size(); j++){
//            cout << ans[i][j] ;
//            cout << ", " ;
//        }
//        cout << "]" << endl;
//    }
//}