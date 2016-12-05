//
//  388_Longest_Absolute_File_Path.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/22/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"



class Solution {
public:
    int lengthLongestPath(string input) {
        input += '\n';
        stack<string> paths;
        int pathLen = 0;
        int tabCnt = 0;
        string buf = "";
        bool isFile = false;
        int maxPathLen = 0;
        for(char ch : input){
            if(ch == '\n'){
                tabCnt = 0;
                if(isFile){
                    maxPathLen = max(maxPathLen, pathLen + (int)buf.size());
                }else{
                    paths.push(buf);
                    pathLen += (int)buf.size() + 1;
                }
                buf = "";
                isFile = false;
            }else if(ch == '\t'){
                tabCnt++;
            }else{
                while(paths.size() > tabCnt){
                    pathLen -= paths.top().size() + 1;
                    paths.pop();
                }
                if(ch == '.'){
                    isFile = true;
                }
                buf += ch;
            }
        }
        return maxPathLen;
    }
};
