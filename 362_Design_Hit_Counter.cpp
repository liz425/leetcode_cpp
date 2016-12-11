//
//  362_Design_Hit_Counter.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/8/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class HitCounter2 {
    //hit() T = O(1), getHits() T = O(300)
    vector<int> TS;
    vector<int> hits;
public:
    /** Initialize your data structure here. */
    HitCounter2() {
        TS.resize(300, 0);
        hits.resize(300, 0);
    }
    
    /** Record a hit.
     @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        int index = timestamp % 300;
        if(TS[index] == timestamp){
            hits[index]++;
        }else{
            TS[index] = timestamp;
            hits[index] = 1;
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
     @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int sum = 0;
        for(int i = 0; i < 300; ++i){
            if(TS[i] > timestamp - 300){
                sum += hits[i];
            }
        }
        return sum;
    }
};




class HitCounter {
    //hit() T = O(1), getHits(), T = size of hits prior to 5 mins
    //Here, we remove expired hits only on getHits() operation. Sure, we could carry out this operation in hit() function
    //The total time consumed will be the same, however, the later solution will consume less memory, and reduce getHit() latency.
    deque<pair<int, int>> counter;
    long totalHits;
public:
    /** Initialize your data structure here. */
    HitCounter() {
        totalHits = 0;
    }
    
    /** Record a hit.
     @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        //We can also remove expired hits in hit().
        //Although it will not improve overall all operations time
        //This will reduce memory consumption and prevent high latency of getHits().
        /*
        while(!counter.empty() && counter.front().first <= timestamp - 300){
            totalHits -= counter.front().second;
            counter.pop_front();
        }
        */
        if(!counter.empty() && counter.back().first == timestamp){
            counter.back().second++;
        }else{
            counter.push_back(make_pair(timestamp, 1));
        }
        totalHits++;
    }
    
    /** Return the number of hits in the past 5 minutes.
     @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while(!counter.empty() && counter.front().first <= timestamp - 300){
            totalHits -= counter.front().second;
            counter.pop_front();
        }
        return (int)totalHits;
    }
};
