//
//  204_Count_Primes.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/23/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution4 {
    //same algo as solution3, remove situation of "i = 2", just need to check odd number, 48 ms
public:
    int countPrimes(int n) {
        if(n < 3) return 0;
        bool isPrime[n];
        for(int i = 2; i < n; i++){
            isPrime[i] = true;
        }
        int count = 1;
        int i = 3;
        for(i = 3; i * i < n; i = i + 2){
            if(!isPrime[i]) continue;
            count++;
            for(int j = i * i; j < n; j += i){
                isPrime[j] = false;
            }
        }
        for(; i < n; i = i + 2){
            if(isPrime[i]){
                count++;
            }
        }
        return count;
    }
};


class Solution3 {
    //same algo with solution2, change vector into array, much faster, 56 ms
public:
    int countPrimes(int n) {
        bool isPrime[n];
        for(int i = 2; i < n; i++){
            isPrime[i] = true;
        }
        int count = 0;
        int i = 2;
        for(i = 2; i * i < n; i++){
            if(!isPrime[i]) continue;
            count++;
            for(int j = i * i; j < n; j += i){
                isPrime[j] = false;
            }
        }
        for(; i < n; i++){
            if(isPrime[i]){
                count++;
            }
        }
        return count;
    }
};


class Solution2 {
    //Sieve of Eratosthenes algorithm, faster, 392ms
public:
    int countPrimes(int n) {
        vector<bool> isPrime (n, true);
        int count = 0;
        int i = 2;
        for(i = 2; i * i < n; i++){
            if(!isPrime[i]) continue;
            count++;
            for(int j = i * i; j < n; j += i){
                isPrime[j] = false;
            }
        }
        for(; i < n; i++){
            if(isPrime[i]){
                count++;
            }
        }
        return count;
    }
};


class Solution {
    //check isPrime by division, really slow, 616 ms
public:
    int countPrimes(int n) {
        vector<int> primes;
        primes.push_back(2);
        int cnt = 1;
        for(int i = 3; i < n; i++){
            int k = 0;
            bool found = true;
            while(primes[k] * primes[k] <= i){
                if(i % primes[k] == 0){
                    found = false;
                    break;
                }
                k++;
            }
            if(found){
                primes.push_back(i);
                cnt++;
            }
        }
        return (n < 3)? 0 : cnt;
    }
};

/*
int main(){
    Solution ss;
    int a = ss.countPrimes(12312532241531);
}
*/