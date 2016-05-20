//
//  068_Text_Justification.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 5/12/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int len = (int)words.size();
        int start = 0;
        int sum = -1;
        vector<string> result;
        if(len == 0){
            return result;
        }
        for(int i = 0; i < len; i++){
            if(sum + words[i].size() + 1 <= maxWidth){
                sum += words[i].size() + 1;
            } else{
                int remain = maxWidth - sum;
                int num = i - start - 1;
                string tmp = words[start];
                if(num == 0){
                    tmp = tmp + string(maxWidth - tmp.size(), ' ');
                }else{
                    for(int j = start + 1; j < i; j++){
                        int k = (j - start <= remain % num)? (remain / num + 2) : (remain / num + 1);
                        tmp += string(k, ' ') + words[j];
                    }
                }
                result.push_back(tmp);
                sum = (int)words[i].size();
                start = i;
            }
        }
        string tmp;
        for(int i = start; i < len; i++){
            tmp = tmp + ' ' + words[i];
        }
        tmp = tmp.substr(1, tmp.size()) + string(maxWidth - tmp.size() + 1, ' ');
        result.push_back(tmp);
        return result;
    }
};

/*
int main(){
    Solution ss;
    vector<string>words = {"a", "b", "c", "d", "e"};
    int maxWidth = 1;
    vector<string> result = ss.fullJustify(words, maxWidth);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << endl;
    }
}
*/