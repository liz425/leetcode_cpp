//
//  411_Minimum_Unique_Word_Abbreviation.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/19/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"



class Solution {
private:
    int minLen;
    string minString;
    string _target;
    int n;
    void DFS(int first, int pick, int pickLen, vector<int>& bitDict, int start){
        if(pickLen > minLen)
            return;
        int i;
        for(i = start; i < (int)bitDict.size(); ++i){
            if((bitDict[i] & pick) == 0){      //abbreviations conflict
                break;
            }
        }
        if(i == (int)bitDict.size()){
            if(pickLen < minLen){
                minLen = pickLen;
                minString = getString(pick);
            }
        }else{
            for(int j = first; j < n; ++j){
                int mask = 1 << j;
                if((pick & mask) == 0){
                    pick |= mask;
                    int newPickLen = pickLen;
                    if(j > 0 && (pick & (mask >> 1)) == 0){
                        newPickLen++;
                    }
                    if(j < n - 1 && (pick & (mask << 1)) == 0){
                        newPickLen++;
                    }
                    DFS(j + 1, pick, newPickLen, bitDict, i);
                    pick &= ~mask;
                }
            }
        }
        return;
    }
    string getString(int pick){
        string result = "";
        int cnt = 0;
        int mask = 1;
        for(int i = 0; i < n; ++i){
            if((pick & mask) == 0){
                cnt++;
            }else{
                if(cnt > 0){
                    result += to_string(cnt);
                    cnt = 0;
                }
                result += _target[i];
            }
            mask = mask << 1;
        }
        if(cnt > 0){
            result += to_string(cnt);
        }
        return result;
    }
    int getBits(string target, string str){
        int result = 0;
        int mask = 1;
        for(int i = 0; i < (int)target.size(); ++i){
            if(target[i] != str[i]){
                result |= mask;
            }
            mask = mask << 1;
        }
        return result;
    }
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        minLen = INT_MAX;
        minString = "";
        _target = target;
        n = (int)target.size();
        if(n == 0)
            return "";
        vector<int> bitDict;
        for(int i = 0; i < (int)dictionary.size(); ++i){
            if(target.size() == dictionary[i].size()){
                bitDict.push_back(getBits(target, dictionary[i]));
            }
        }
        int pick = 0;
        DFS(0, pick, 1, bitDict, 0);
        return minString;
    }
};


/*
int main(void){
    Solution ss;
    string target = "apple";
    vector<string> dictionary = {"kkkk"};
    cout << ss.minAbbreviation(target, dictionary) << endl;
}
*/
