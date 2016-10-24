//
//  056_Merge_Intervals.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/21/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
    //Basically the same idea with Solution, but more clear.
public:
    static bool comp(Interval a, Interval b){
        return (a.start == b.start)? a.end < b.end : a.start < b.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if(intervals.empty())
            return result;
        sort(intervals.begin(), intervals.end(), comp);
        Interval current = intervals[0];
        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i].start <= current.end){
                current.end = max(current.end, intervals[i].end);
            }else{
                result.push_back(current);
                current = intervals[i];
            }
        }
        result.push_back(current);
        return result;
    }
};



class Solution {
public:
    static bool comparator(Interval x, Interval y){
        return (x.start < y.start);
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() <= 1){
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), comparator);
        vector<Interval> result;
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (result.back().end < intervals[i].start)
                result.push_back(intervals[i]);
            else
                result.back().end = max(result.back().end, intervals[i].end);
        }
        return result;
    }
};
