//
//  216_Combination_Sum_III.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 3/22/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
private:
    void DFS(vector<vector<int>>& result, vector<int>& current, int j, int k, int n){
        if(k == 0){
            if(n == 0 && !current.empty()){
                result.push_back(current);
            }
            return;
        }
        for(int i = j; i <= 9; ++i){
            if(i * k > n){
                break;
            }
            current.push_back(i);
            DFS(result, current, i + 1, k - 1, n - i);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;
        DFS(result, current, 1, k, n);
        return result;
    }
};


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
