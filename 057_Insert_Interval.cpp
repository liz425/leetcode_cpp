//
//  057_Insert_Interval.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 8/31/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        bool expanded = false;
        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i].end < newInterval.start){
                result.push_back(intervals[i]);
            }else if(intervals[i].start > newInterval.end){
                if(!expanded){
                    expanded = true;
                    result.push_back(newInterval);
                }
                result.push_back(intervals[i]);
            }else{
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }
        if(!expanded)
            result.push_back(newInterval);
        return result;
    }
};


/*
int main(){
    Solution ss;
    vector<Interval> intervals = {Interval(1,2),Interval(3,5),Interval(6,7),Interval(8,10),Interval(12,16)};
    ss.insert(intervals, Interval(4, 9));
    return 0;
}
*/