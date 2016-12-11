//
//  393_UTF-8_Validation.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/9/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    int getLeadingOnes(int num){
        int cnt = 0;
        for(int i = 0; i < 8; ++i){
            //Notice!!!!  '>' has higher preference than '&'
            if((num & 0x80) > 0){
                cnt++;
                num = num << 1;
            }else{
                break;
            }
        }
        return cnt;
    }
    bool isLeading10(int num){
        return (num & 0xc0) == 0x80;
    }
public:
    bool validUtf8(vector<int>& data) {
        int n = (int)data.size();
        int i = 0;
        while(i < n){
            //LeadingOnes can be either 0 or >= 2. SHOULD NOT be 1 !!!!!
            int k = getLeadingOnes(data[i++]) - 1;
            if(k == 0)
                return false;
            while(k-- > 0){
                if(i >= n || !isLeading10(data[i++])){
                    return false;
                }
            }
        }
        return true;
    }
};

/*
int main(void){
    Solution ss;
    vector<int> data = {145};
    cout << ss.validUtf8(data) << endl;
}
*/
