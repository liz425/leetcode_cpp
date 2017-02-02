//
//  288_Unique_Word_Abbreviation.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 1/22/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"


class ValidWordAbbr {
    unordered_map<string, string> abreDict;
public:
    ValidWordAbbr(vector<string> dictionary) {
        for(string& word : dictionary){
            string abre = getAbre(word);
            if(abreDict.find(abre) == abreDict.end()){
                abreDict[abre] = word;
            }else if(abreDict[abre] != word){
                //If multiple strings share the same abbreviation, then the key is invalid, just set it as ""
                //Since we only care "unique abbreviation". When it's already non-unique, discard it.
                abreDict[abre] = "";
            }
        }
    }
    
    bool isUnique(string word) {
        string abre = getAbre(word);
        return (abreDict.find(abre) == abreDict.end()) || (abreDict[abre] == word);
    }
    string getAbre(string word){
        string abre;
        if(word.size() <= 2){
            abre = word;
        }else{
            abre = word.front() + to_string((int)word.size() - 2) + word.back();
        }
        return abre;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */
