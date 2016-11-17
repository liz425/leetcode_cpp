//
//  049_Group_Anagrams.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/13/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"



class Solution3 {
    //Here we write our own sort function.
    //Since it's only lower case letter, we can use counting sort in O(k), k is average string length
    //Thus over all it's has T = O(n*k)
    //Indeed this solution run fastest.
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, multiset<string>> mp;
        for (string s : strs) {
            string t = strSort(s);
            mp[t].insert(s);
        }
        vector<vector<string>> anagrams;
        for (auto m : mp) {
            vector<string> anagram(m.second.begin(), m.second.end());
            anagrams.push_back(anagram);
        }
        return anagrams;
    }
private:
    string strSort(string& str) {
        int count[26] = {0};
        int n = (int)str.length();
        for (int i = 0; i < n; i++)
            count[str[i] - 'a']++;
        int p = 0;
        string result(n, 'a');
        for (int j = 0; j < 26; j++)
            for (int i = 0; i < count[j]; i++)
                result[p++] += j;
        return result;
    }
};



class keyHasher{
public:
    //notice that here should be two const
    size_t operator()(const vector<int>& strs) const {
        string hashKey = "";
        for(int i = 0; i < (int)strs.size(); ++i){
            hashKey += to_string(strs[i]) + "#";
        }
        std::hash<string> hasher;
        return hasher(hashKey);
    }
};

class Solution2 {
    //Use vector<int> as a hash key, then for every string, do not need to sort which is nlog(n)
    //Just cnt times of every letter shows and use unordered_map to distinguish them.
    //Theoritically this solution is faster than the firs, but actually it's slower
    //Since the test case are not strong, string are not long engough that std::sort() is quick enough
    //But cnt and the keyHasher has more overhead
public:
    vector<int> cnt(string str){
        vector<int> result(26, 0);
        for(char ch : str){
            result[ch - 'a']++;
        }
        return result;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<vector<int>, vector<string>, keyHasher> anagrams;
        for(auto& str : strs){
            vector<int> wordCnt = cnt(str);
            anagrams[wordCnt].push_back(str);
        }
        vector<vector<string>> result;
        for(auto& item : anagrams){
            result.push_back(item.second);
        }
        return result;
    }
};





class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for(auto& str : strs){
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            anagrams[sortedStr].push_back(str);
        }
        vector<vector<string>> result;
        for(auto& item : anagrams){
            result.push_back(item.second);
        }
        return result;
    }
};
