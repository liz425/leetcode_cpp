//
//  460_LFU_Cache.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/1/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Node{
public:
    int key;
    int val;
    int cnt;
    Node(int k, int v, int c):key(k), val(v), cnt(c){}
    Node():key(0), val(0), cnt(0){}
};


class LFUCache {
private:
    int size = 0;
    unordered_map<int, list<Node>> data;
    unordered_map<int, list<Node>::iterator> hm;
    int _capacity;
    int lastFre;
public:
    LFUCache(int capacity) {
        _capacity = capacity;
        lastFre = 0;
    }
    
    int get(int key) {
        if(hm.find(key) == hm.end()){
            return -1;
        }
        int cnt = hm[key]->cnt;
        if(data.find(cnt + 1) == data.end()){
            data[cnt + 1] = list<Node>(0);
        }
        data[cnt + 1].push_front(*hm[key]);
        data[cnt + 1].front().cnt++;
        data[cnt].erase(hm[key]);
        if(data[lastFre].empty()){
            lastFre++;
        }
        hm[key] = data[cnt + 1].begin();
        return hm[key]->val;
    }
    
    void set(int key, int value) {
        if(_capacity == 0){
            return;
        }
        if(hm.find(key) == hm.end()){
            //insert new key-val pair
            if(size == _capacity){
                //remove last one
                hm.erase(data[lastFre].back().key);
                data[lastFre].pop_back();
                size--;
            }
            if(data.find(1) == data.end()){
                data[1] = list<Node>(0);
            }
            data[1].push_front(Node(key, value, 1));
            hm[key] = data[1].begin();
            size++;
            lastFre = 1;
        }else{
            hm[key]->val = value;
            get(key);
        }
    }
};

/*
int main(void){
    LFUCache obj = LFUCache(2);
    obj.set(1, 1);
    obj.set(2, 2);
    cout << obj.get(1) << endl;
    obj.set(3, 3);
    cout << obj.get(2) << endl;
    cout << obj.get(3) << endl;
    obj.set(4, 4);
    cout << obj.get(1) << endl;
    cout << obj.get(3) << endl;
    cout << obj.get(4) << endl;
}
 */
