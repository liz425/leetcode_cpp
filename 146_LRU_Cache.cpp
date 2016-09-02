//
//  146_LRU_Cache.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 7/29/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

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
    
    void set(int key, int value) {
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
    LRUCache cache(1);
    cout << cache.get(1) << endl;
    cache.set(1, 100);
    cout << cache.get(1) << endl;
    cache.set(2, 200);
    cache.get(1);
    cache.set(2, 150);
    cache.set(3, 300);
    cout << cache.get(2) << endl;
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
}
*/