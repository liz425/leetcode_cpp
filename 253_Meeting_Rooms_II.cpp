//
//  253_Meeting_Rooms_II.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/4/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
    //sweep line, T = O(n * logn)
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        //pair.second: 1 for meeting start, 0 for meeting ends
        //Thus at the same time, meeting ends go before meeting start
        vector<pair<int, int>> events;
        for(auto interval : intervals){
            events.push_back(make_pair(interval.start, 1));
            events.push_back(make_pair(interval.end, 0));
        }
        sort(events.begin(), events.end());
        int cnt = 0;
        int maxCnt = 0;
        for(auto event : events){
            if(event.second == 1){
                cnt++;
            }else{
                cnt--;
            }
            maxCnt = max(maxCnt, cnt);
        }
        return maxCnt;
    }
};



class Solution {
    //Sorting: t = O(n * logn), minHeap: t = (n * logn).
    //Total: T = O(n * logn)
    //maintain a min_heap, record the end time of each meeting
    //when we have a new meeting, if its start time is larger than the top element of the heap
    //then we can reuse the top meeting room for a new meeting
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
