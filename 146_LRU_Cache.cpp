//
//  146_LRU_Cache.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 7/29/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class LRUCache3 {
    //Same implementation wieh LRUCache2, just create two memeber functions for those common operations.
    //Notice: CAN NOT assign list<>::reverse_iterator to list<>::iterator.
    //E.g. If we want the iterator storing the last item, we SHOULD NOT use:
    // THIS IS WRONG:   list<>::iterator it = ls.rbegin();
    //Instead, we should use the following:
    // THIS IS Correct: list<>::iterator it = next(ls.begin(), -1);
private:
    list<pair<int, int>> data;
    unordered_map<int, list<pair<int, int>>::iterator> hm;
    int _capacity;
    void setAsRecent(list<pair<int, int>>::iterator it){
        data.push_back(*it);
        data.erase(it);
        hm[data.back().first] = next(data.end(), -1);
        return;
    }
    void eraseData(list<pair<int, int>>::iterator it){
        hm.erase(it->first);
        data.erase(it);
        return;
    }
public:
    LRUCache3(int capacity):_capacity(capacity) {
        
    }
    
    int get(int key) {
        if(hm.find(key) == hm.end()){
            return -1;
        }else{
            setAsRecent(hm[key]);
            return hm[key]->second;
        }
    }
    
    void put(int key, int value) {
        if(hm.find(key) != hm.end()){
            hm[key]->second = value;
            setAsRecent(hm[key]);
        }else{
            if(data.size() >= _capacity){
                eraseData(data.begin());
            }
            data.emplace_back(key, value);
            hm[key] = next(data.end(), -1);
        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */



class LRUCache2{
    //using STL list<>
    unordered_map<int, list<pair<int, int>>::iterator> hash;
    int m_capacity;
    list<pair<int, int>> cache;
public:
    LRUCache2(int capacity) {
        m_capacity = capacity;
    }
    
    int get(int key) {
        if(hash.find(key) == hash.end())
            return -1;
        auto it = hash[key];
        auto item = *it;
        cache.erase(it);
        cache.push_front(item);
        hash[key] = cache.begin();
        return item.second;
    }
    
    void put(int key, int value) {
        if(hash.find(key) != hash.end())
            cache.erase(hash[key]);  // now cache_size == (hash_size - 1)
        if(cache.size() == m_capacity){  //note that in C++98, list.size() takes linear time
            hash.erase(cache.back().first);
            cache.pop_back();
        }
        cache.push_front(make_pair(key, value));
        hash[key] = cache.begin();
    }
};



class LRUCache{
    //use double linked list and hashtable
public:
    struct node{
        int key;
        int val;
        node* pre;
        node* next;
        node(int k, int v, node* p, node* n):key(k),val(v),pre(p),next(n){}
    };
    unordered_map<int, node*> hash;
    int maxCap;
    node* head, *tail;
    LRUCache(int capacity) {
        maxCap = capacity;
        head = tail = NULL;
    }
    
    int get(int key) {
        if(hash.find(key) == hash.end())
            return -1;
        else{
            node* recentNode = hash[key];
            if(recentNode->pre){
                recentNode->pre->next = recentNode->next;
                if(recentNode->next){
                    recentNode->next->pre = recentNode->pre;
                }else{
                    tail = recentNode->pre;
                }
                recentNode->next = head;
                head->pre = recentNode;
                recentNode->pre = NULL;
                head = recentNode;
            }
            return hash[key]->val;
        }
    }
    
    void put(int key, int value) {
        node* recentNode;
        if(hash.find(key) != hash.end()){
            recentNode = hash[key];
            recentNode->val = value;
            if(recentNode->pre){
                recentNode->pre->next = recentNode->next;
                if(recentNode->next){
                    recentNode->next->pre = recentNode->pre;
                }else{
                    tail = recentNode->pre;
                }
                recentNode->next = head;
                head->pre = recentNode;
                recentNode->pre = NULL;
                head = recentNode;
            }
        }else{
            if(hash.size() == maxCap){
                if(tail->pre)
                    tail->pre->next = NULL;
                node* last = tail;
                tail = tail->pre;
                hash.erase(last->key);
                delete last;
            }
            node* newNode = new node(key, value, NULL, head);
            if(head)
                head->pre = newNode;
            head = newNode;
            hash[key] = newNode;
            if(!tail)
                tail = newNode;
        }
    }
};


/*
int main(){
    LRUCache3 cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;
    cache.put(3, 3);
    cout << cache.get(2) << endl;
    cache.put(4, 4);
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;
}
*/
