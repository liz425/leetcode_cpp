//
//  014_Longest_Common_Prefix.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 4/23/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"



class Solution2 {
public:
    //DFS, divide and conquer, still T = O(m*n)
    string longestCommonPrefix(vector<string>& strs) {
        return DFS(strs, 0, (int)strs.size() - 1);
    }
    string DFS(vector<string>& strs, int start, int end){
        if(start > end)
            return "";
        if(start == end)
            return strs[start];
        int mid = start + (end - start) / 2;
        string str1 = DFS(strs, start, mid);
        string str2 = DFS(strs, mid + 1, end);
        string result = "";
        for(int i = 0; i < str1.size() && i < str2.size(); ++i){
            if(str1[i] == str2[i])
                result += str1[i];
            else
                break;
        }
        return result;
    }
};


class Solution {
public:
    //Garbage code...
    //Vertical, T = O(m*n)
    string longestCommonPrefix(vector<string>& strs) {
        string longest = "";
        int i = 0;
        if(strs.empty()){
            return longest;
        }
        while(strs[0][i] != '\0'){
            for(int j = 1; j < (int)strs.size(); j++){
                if(strs[j][i] != strs[0][i]){
                    return longest;
                }
            }
            longest += strs[0][i++];
        }
        return longest;
    }
};
