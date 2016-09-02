//
//  158_Read_N_Characters_Given_Read4-II_Call_multiple_times.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/2/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

// Forward declaration of the read4 API.
int pos = 0;
int read4(char *buf){
    string str = "abcdefghijklmnopqrstuvwxyz";
    int i = pos;
    int result = min(4, (int)str.size() - pos);
    for(i = pos; i < min(pos + 4, (int)str.size()); ++i){
        buf[i - pos] = str[i];
    }
    pos = i;
    return result;
}


class Solution2 {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    string remainBuf = "";
    int remainLen = 0;
    bool reachFileEnd = false;
    int read(char *buf, int n) {
        int i = 0;
        int cnt = 0;
        for(i = 0; i < min(remainLen, n); ++i){
            buf[i] = remainBuf[i];
        }
        remainBuf = remainBuf.substr(i);
        cnt += i;
        n -= i;
        remainLen -= i;
        if(reachFileEnd || n <= 0)
            return i;
        int k = n / 4;
        char read4Buf[4];
        for(i = 0; i < k; ++i){
            int fetch = read4(read4Buf);
            for(int j = 0; j < fetch; ++j){
                buf[cnt + j] = read4Buf[j];
            }
            cnt += fetch;
            if(fetch != 4){
                reachFileEnd = true;
                return cnt;
            }
        }
        n = n % 4;
        if(n != 0){
            int fetch = read4(read4Buf);
            for(i = 0; i < min(fetch, n); ++i){
                buf[cnt + i] = read4Buf[i];
            }
            cnt += i;
            if(fetch < 4)
                reachFileEnd = true;
            if(n < fetch){
                for(i = n; i < fetch; ++i){
                    remainBuf.push_back(read4Buf[i]);
                }
                remainLen = fetch - n;
            }
        }
        return cnt;
    }
};


class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    string Gbuffer = "";
    int bufLen = 0;
    int read(char *buf, int n) {
        if(n > bufLen && bufLen % 4 == 0){
            int remain = n - bufLen;
            int k = (remain % 4)? remain / 4 + 1 : remain / 4;
            char read4buf[4];
            for(int i = 0; i < k; ++i){
                int incre = read4(read4buf);
                for(int j = 0; j < incre; ++j){
                    Gbuffer += read4buf[j];
                }
                bufLen += incre;
                if(incre != 4)
                    break;
            }
        }
        int result = min(bufLen, n);
        for(int i = 0; i < result; ++i){
            buf[i] = Gbuffer[i];
        }
        return result;
    }
};

/*
int main(){
    Solution2 ss;
    for(int i = 0; i < 10; i++){
        char ans[20];
        ss.read(ans, i);
        cout << ans << endl;
    }

}
*/