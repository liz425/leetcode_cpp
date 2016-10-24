//
//  406_Queue_Reconstruction_by_Height.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/20/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"



class Solution3 {
    //T = O(n*sqrt(n)), base on Solution1, from shortest to tallest.
    //Break result into sqrt(n) blocks
    //Then find the final position would be first find the block, then find the position, T = sqrt(n) + sqrt(n)
public:
    struct comparator{
        bool operator()(pair<int, int> a, pair<int, int> b){
            return (a.first == b.first)? a.second > b.second : a.first < b.first;
        }
    }comp;
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        int size = (int)people.size();
        vector<int> filled(size, 0);
        vector<pair<int, int>> result(size);
        if(size == 0)
            return result;
        sort(people.begin(), people.end(), comp);
        int blockSize = sqrt(size);
        int blockNum = size / blockSize + ((size % blockSize)? 1 : 0);
        vector<int> voidCnt(blockNum, blockSize);
        for(auto person : people){
            int cnt = 0;
            int i = 0;
            for(i = 0; i < blockNum; ++i){
                if(voidCnt[i] + cnt <= person.second){
                    cnt += voidCnt[i];
                }else{
                    break;
                }
            }
            for(int j = 0; j < blockSize; ++j){
                if(filled[i * blockSize + j] == 0)
                    cnt++;
                if(cnt == person.second + 1){
                    filled[i * blockSize + j] = 1;
                    result[i * blockSize + j] = person;
                    voidCnt[i] -= 1;
                    break;
                }
            }
        }
        return result;
    }
};




class Solution2 {
    //construct from tallest to shortest, T = O(n^2)
public:
    static bool comp(pair<int, int> a, pair<int, int> b){
        return (a.first == b.first)? a.second < b.second : a.first > b.first;
    }
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> result;
        sort(people.begin(), people.end(), comp);
        for(auto person : people){
            result.insert(result.begin() + person.second, person);
        }
        return result;
    }
};



struct comparator{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return (a.first == b.first)? a.second > b.second : a.first < b.first;
    }
}comp;
class Solution {
    //construct from shortest to tallest, T = O(n^2)
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        int size = (int)people.size();
        vector<int> filled(size, 0);
        vector<pair<int, int>> result(size);
        sort(people.begin(), people.end(), comp);
        for(auto person : people){
            int cnt = 0;
            for(int i = 0; i < size; ++i){
                if(filled[i] == 0){
                    cnt++;
                }
                if(cnt == person.second + 1){
                    filled[i] = 1;
                    result[i] = person;
                    break;
                }
            }
        }
        return result;
    }
};
