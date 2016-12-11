//
//  STL_unordered_set.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/10/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class pairhash{
public:
    size_t operator()(const pair<int, int>& p)const{
        return hash<int>()(p.first) ^ hash<int>()(p.first);
    }
};

class pred{
public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const{
        return (a.first == b.first) && (a.second == b.second);
    }
};

/*
int main(void){
    unordered_set<pair<int, int>, pairhash, pred> test;
    test.insert(make_pair(1, 2));
    test.insert(make_pair(2, 1));
    test.insert(make_pair(1, 1));
    test.insert(make_pair(2, 2));
    cout << test.count(make_pair(1, 1)) << endl;
    for(auto item : test){
        cout << "first: " << item.first << ", second: " << item.second << endl;
    }

}
*/
