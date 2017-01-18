//
//  432_All_O_one_Data_Structure.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 1/14/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"


class AllOne {
private:
    unordered_map<string, list<pair<int, unordered_set<string>>>::iterator> hm;
    list<pair<int, unordered_set<string>>> ls;
public:
    /** Initialize your data structure here. */
    AllOne() {
        ls.insert(ls.begin(), make_pair(0, unordered_set<string>{}));
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        //point to beginning of list
        auto it = ls.begin();
        int val = it->first;
        if(hm.find(key) != hm.end()){   //if found, update iterator
            it = hm[key];
            val = it->first;
        }
        it++;   //point to next iterator
        if(it == ls.end() || it->first != val + 1){     //need to create a new list node
            it = ls.insert(it, make_pair(val + 1, unordered_set<string>{}));
        }
        it->second.insert(key);
        if(hm.find(key) != hm.end()){
            it--;
            it->second.erase(key);
            if(it->second.empty()){
                it = ls.erase(it);
            }else{
                it++;
            }
        }
        hm[key] = it;
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(hm.find(key) == hm.end()){
            return;
        }else{
            auto it = hm[key];
            int val = it->first;
            it->second.erase(key);
            if(it->second.empty()){
                it = ls.erase(it);
            }
            if(val == 1){
                hm.erase(key);
            }else{
                --it;
                if(it->first != val - 1){
                    it = ls.insert((++it), make_pair(val - 1, unordered_set<string>{}));
                }
                it->second.insert(key);
                hm[key] = it;
            }
            return;
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        auto it = --ls.end();
        if(it == ls.begin()){
            return "";
        }else{
            return *(it->second.begin());
        }
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        auto it = ++ls.begin();
        if(it == ls.end()){
            return "";
        }else{
            return *(it->second.begin());
        }
    }
};


/*
int main(void){
//Your AllOne object will be instantiated and called as such:
    AllOne obj;
    obj.inc("hello");
    obj.inc("world");
    obj.inc("hello");
    obj.dec("world");
    obj.inc("hello");
    obj.inc("leet");
    string param_3 = obj.getMaxKey();
    string param_4 = obj.getMinKey();
    cout << param_3 << endl;
    cout << param_4 << endl;
}
*/
