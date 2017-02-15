//
//  359_Logger_Rate_Limiter.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 2/6/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"


class Logger {
private:
    unordered_map<string, int> data;
    deque<unordered_map<string, int>::iterator> dq;
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
     If this method returns false, the message will not be printed.
     The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        while(!dq.empty()){
            if(dq.front()->second <= timestamp - 10){
                data.erase(dq.front());
                dq.pop_front();
            }else{
                break;
            }
        }
        if(data.find(message) == data.end()){
            addMessage(timestamp, message);
            return true;
        }else{
            return false;
        }
    }
    bool addMessage(int timestamp, string message){
        auto rtn = data.emplace(message, timestamp);
        if(rtn.second){
            dq.push_back(rtn.first);
        }
        return rtn.second;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */
