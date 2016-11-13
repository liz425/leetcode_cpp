//
//  380_Insert_Delete_GetRandom_O(1).cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/30/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class RandomizedSet2 {
    //Use vector<int> data to store actually val
    //Use unordered_map<int, int> index to store val index for deletion
    //When delete, swap it to the last index, then delete.
    //getRandom is truely O(1), faster than previous solution.
private:
    vector<int> data;
    unordered_map<int, int> index;
public:
    /** Initialize your data structure here. */
    RandomizedSet2() {
        data.clear();
        index.clear();
        srand((int)time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool existed = (index.find(val) != index.end());
        if(!existed){
            index[val] = (int)data.size();
            data.push_back(val);
        }
        return !existed;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        bool existed = (index.find(val) != index.end());
        if(existed){
            swap(data[index[val]], data[(int)data.size() - 1]);
            //now data[index[val]] has been changed to the last element before swap, update its index
            index[data[index[val]]] = index[val];
            data.pop_back();
            index.erase(val);
        }
        return existed;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(data.empty())
            return 0;
        return data[rand() % int(data.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */




class RandomizedSet {
    //Deletion, T = (1 + 2 + 3 + ... + n) * (1 / n) = 2
    //Armotized O(1), but can be as long as O(n) if get the last item.
private:
    unordered_map<int, int> hash;
    int size;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        hash.clear();
        size = 0;
        srand((int)time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        int existed = (hash.find(val) != hash.end());
        if(!existed){
            hash[val] = 1;
            size++;
        }
        return !existed;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        int existed = (hash.find(val) != hash.end());
        if(existed){
            hash.erase(val);
            size--;
        }
        return existed;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if(size == 0)
            return 0;
        int index = rand() % size;
        auto it = hash.begin();
        while(index-- > 0){
            it++;
        }
        return it->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
