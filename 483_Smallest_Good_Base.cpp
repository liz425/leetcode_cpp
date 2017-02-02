//
//  483_Smallest_Good_Base.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 1/23/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"



class Solution2 {
    //T = )
public:
    string smallestGoodBase(string n) {
        long n_long = stol(n);
        for(int i = 60; i >= 2; i--){
            long lo = 2;
            long hi = pow(double(n_long), double(1.0 / (i - 1)));
            while(lo <= hi){
                long mid = lo + (hi - lo) / 2;
                int ans = helper(n_long, mid, i - 1);
                if(ans > 0){
                    hi = mid - 1;
                }else if(ans < 0){
                    lo = mid + 1;
                }else{
                    return to_string(mid);
                }
            }
        }
        return to_string(n_long - 1);
    }
    int helper(long n_long, long k, int i){
        long val = 1;
        for(int j = 0; j < i; j++){
            val = val * k + 1;
        }
        if(val > n_long){
            return 1;
        }else if(val < n_long){
            return -1;
        }else{
            return 0;
        }
    }
};


class Solution {
    //Correct but TLE.
    long minBase = 0;
public:
    string smallestGoodBase(string n) {
        long n_long = stol(n);
        long root = long(sqrt(n_long - 1));
        vector<long> factors = factorization(n_long - 1);
        minBase = n_long - 1;
        findBase(factors, n_long, root, 1, 0);
        return to_string(minBase);
    }
    void findBase(vector<long>& factors, long n_long, long root, long current, int index){
        int len = (int)factors.size();
        for(int i = index; i < len; ++i){
            if(i == index || factors[i] != factors[i - 1]){
                if(current * factors[i] > root){
                    break;
                }else if(DFS(n_long, current * factors[i])){
                    minBase = min(minBase, current * factors[i]);
                    break;
                }else{
                    findBase(factors, n_long, root, current * factors[i], i + 1);
                }
            }
        }
    }
    bool DFS(long n, long k){
        if(n == 1){
            return true;
        }else if((n - 1) % k){
            return false;
        }else{
            return DFS((n - 1) / k, k);
        }
    }
    vector<long> factorization(long n){
        long i = 2;
        long root = long(sqrt(n));
        vector<long> result;
        while(i <= root && n > 1){
            if(n % i == 0){
                result.push_back(i);
                n /= i;
            }else{
                i++;
            }
        }
        if(n != 1){
            result.push_back(n);
        }
        return result;
    }
};


/*
int main(void){
    Solution2 ss;
    cout << ss.smallestGoodBase("821424692950225218") << endl;
}
*/
