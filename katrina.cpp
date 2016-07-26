//
//  katrina.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 7/26/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


bool isAPrime(int n){
    if(n < 2 || (n > 2 && n % 2 == 0)){
        return false;
    }else{
        for(int i = 2; i <= sqrt(n); ++i){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
}

int largestPartialPrime(int n){
    if(n < 0)
        n = -n;
    string ss = to_string(n);
    cout << ss << endl;
    int size = (int)ss.size();
    int maxPrime = 0;
    for(int i = 0; i < size; ++i){
        for(int j = i; j < size; ++j){
            int candidate = stoi(ss.substr(i, j - i + 1));
            if(isAPrime(candidate)){
                maxPrime = max(maxPrime, candidate);
            }
        }
    }
    return maxPrime;
}



string factorialFactors(int n){
    //first find all prime nums <= n
    vector<bool> isPrime(n + 1, true);
    for(int i = 4; i <= n; i = i + 2){
        isPrime[i] = false;
    }
    for(int i = 3; i * i <= n; i = i + 2){
        if(!isPrime[i]) continue;
        for(int j = i * i; j <= n; j += i){
            isPrime[j] = false;
        }
    }
    string result;
    for(int i = 2; i <= n; ++i){
        if(isAPrime(i)){
            int div = n;
            int sum = 0;
            while(div > 0){
                div /= i;
                sum += div;
            }
            result += " " + to_string(sum);
        }
    }
    return result.substr(1);
}

/*
int main(){
    clock_t start, end;
    start = clock();
    string result = factorialFactors(13886699);
    end = clock();
    cout << "result: " << result << endl;
    double time_consumed = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    cout << "time: " << time_consumed << endl;
}
*/