//
//  281_Zigzag_Iterator.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/8/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class ZigzagIterator {
    list<pair<vector<int>::iterator, vector<int>::iterator>> its;
    list<pair<vector<int>::iterator, vector<int>::iterator>>::iterator listIt;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(!v1.empty()){
            its.push_back(make_pair(v1.begin(), v1.end()));
        }
        if(!v2.empty()){
            its.push_back(make_pair(v2.begin(), v2.end()));
        }
        listIt = its.begin();
    }
    
    int next() {
        int result = *((*listIt).first);
        (*listIt).first++;
        if((*listIt).first == (*listIt).second){
            listIt = its.erase(listIt);
        }else{
            listIt++;
        }
        if(listIt == its.end()){
            listIt = its.begin();
        }
        return result;
    }
    
    bool hasNext() {
        return !its.empty();
    }
};
