//
//  336_Palindrome_Pairs.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/28/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    bool isPalindrome(string& word){
        int i = 0, j = (int)word.size() - 1;
        while(i < j){
            if(word[i] != word[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> dict;
        vector<vector<int>> result;
        int n = (int)words.size();
        for(int i = 0; i < n; ++i){
            dict[words[i]] = i;
        }
        for(int i = 0; i < n; ++i){
            if(words[i] == "")
                continue;
            for(int j = 0; j <= words[i].size(); ++j){
                string str1 = words[i].substr(0, j);
                string str2 = words[i].substr(j);
                reverse(str1.begin(), str1.end());
                reverse(str2.begin(), str2.end());
                //to remove duplictes of, we make sure that when words[i] == ss1
                //ss1|ss2, len_of_ss1 >= len_of_ss2
                //ss2|ss1, len_of_ss1 > len_of_ss2
                //Thus, if two string has same lens "abc" "cba", and when we are considering "abc" as words[i], it will only appear in the prefix part
                if(j > 0 && dict.find(str2) != dict.end() && isPalindrome(str1)){
                    result.push_back(vector<int>{dict[str2], i});
                }
                if(dict.find(str1) != dict.end() && isPalindrome(str2)){
                    int index = dict[str1];
                    if(index != i)  //avoid "abcba" comparing to itself
                        result.push_back(vector<int>{i, index});
                }
            }
        }
        return result;
    }
};

/*
int main(void){
    Solution ss;
    vector<string> words = {"abcd","dcba","lls","s","sssll"};
    ss.palindromePairs(words);
}
 */
