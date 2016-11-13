//
//  068_Text_Justification.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 5/12/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
    //Same idea, rewrite.
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int wordCnt = 0;
        int wordLen = 0;
        for(int i = 0; i < (int)words.size(); ++i){
            if(wordLen + (int)words[i].size() + wordCnt <= maxWidth){
                wordCnt++;
                wordLen += (int)words[i].size();
            }else{
                string candid = "";
                if(wordCnt == 1){
                    candid = words[i - 1] + string(maxWidth - wordLen, ' ');
                }else{
                    int averSpace = (maxWidth - wordLen) / (wordCnt - 1);
                    int remain = (maxWidth - wordLen) % (wordCnt - 1);
                    for(int j = 0; j < wordCnt; j++){
                        candid += words[i - wordCnt + j];
                        int k = 0;
                        if(j < remain){
                            k = averSpace + 1;
                        }else if(j < wordCnt - 1){
                            k = averSpace;
                        }else{
                            k = 0;
                        }
                        candid += string(k, ' ');
                    }
                }
                result.push_back(candid);
                wordCnt = 1;
                wordLen = (int)words[i].size();
            }
        }
        string candid = words[(int)words.size() - wordCnt];
        for(int i = 1; i < wordCnt; ++i){
            candid += " " + words[(int)words.size() - wordCnt + i];
        }
        candid += string(maxWidth - wordLen - wordCnt + 1, ' ');
        result.push_back(candid);
        return result;
    }
};



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
