
//
//  252_Meeting_Rooms.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/15/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution3 {
    //same as Solution, just use Lamda as comparator
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = (int)intervals.size();
        auto comp = [](Interval a, Interval b) -> bool{
            return (a.start == b.start) ? a.end < b.end : a.start < b.start;
        };
        sort(intervals.begin(), intervals.end(), comp);
        for(int i = 1; i < n; ++i){
            if(intervals[i - 1].end > intervals[i].start){
                return false;
            }
        }
        return true;
    }
};



class Solution2 {
    //sweep line, T = O(n * logn)
    //Slowr than solution 1, though have same T, here n = 2 * number_of_meetings
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        //pair.second: 1 for meeting start, 0 for meeting ends
        //Thus at the same time, meeting ends go before meeting start
        vector<pair<int, int>> events;
        for(auto interval : intervals){
            events.push_back(make_pair(interval.start, 1));
            events.push_back(make_pair(interval.end, 0));
        }
        sort(events.begin(), events.end());
        int cnt = 0;
        for(auto event : events){
            if(event.second == 1){
                cnt++;
            }else{
                cnt--;
            }
            if(cnt > 1){
                return false;
            }
        }
        return true;
    }
};




class comp{
public:
    bool operator()(Interval a, Interval b){
        return (a.start == b.start)? a.end < b.end : a.start < b.start;
    }
};

class Solution {
    //Sorting, T = O(n*logn), n = number_of_meetings
private:
    static comp comparator;
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), comparator);
        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i].start < intervals[i - 1].end){
                return false;
            }
        }
        return true;
    }
};
