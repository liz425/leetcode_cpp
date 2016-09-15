//
//  253_Meeting_Rooms_II.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/4/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    static bool comp(Interval& x, Interval& y){
        return x.start < y.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty())
            return 0;
        sort(intervals.begin(), intervals.end(), comp);
        priority_queue<int, vector<int>, std::greater<int>> rooms;
        rooms.push(0);
        for(auto& meeting : intervals){
            if(meeting.start >= rooms.top()){
                rooms.pop();
            }
            rooms.push(meeting.end);
        }
        return (int)rooms.size();
    }
};

/*
int main(){
    Solution ss;
    vector<Interval> intervals = {Interval(0,30), Interval(5,10), Interval(15, 20)};
    cout << ss.minMeetingRooms(intervals) << endl;
}
*/