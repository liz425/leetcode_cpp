//
//  071_Simplify_Path.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/14/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        string dir = "";
        int n = (int)path.size();
        for(int i = 0; i < n; ++i){
            dir += path[i];
            if(i < n - 1 && path[i + 1] != '/'){
                continue;
            }
            if(dir == "/.."){
                if(!dirs.empty()){
                    dirs.pop_back();
                }
            }else if(dir != "/." && dir != "/"){
                dirs.push_back(dir);
            }
            dir = "";
        }
        string result = "";
        for(string str : dirs){
            result += str;
        }
        if(result.empty()){
            return "/";
        }else{
            return result;
        }
    }
};
