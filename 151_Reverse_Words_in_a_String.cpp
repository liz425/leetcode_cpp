//
//  151_Reverse_Words_in_a_String.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 5/29/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution2 {
    //inplace solution
public:
    void removeLeadingZeros(string &s){
        int i = 0;
        int len = (int)s.size();
        while(i < len && s[i] == ' '){
            i++;
        }
        s = s.substr(i);
    }
    void removeContinuousZeros(string &s){
        int i = 0;
        while(i < s.size()){
            if(i > 0 && s[i] == ' ' && s[i-1] == ' '){
                //Have to assign erase len = 1, otherwise it will erase all char until the end
                s.erase(i, 1);
            }else{
                i++;
            }
        }
    }
    void reverseWords(string &s) {
        //remove leading zeros => reverse => remove leading zeros again
        removeLeadingZeros(s);
        reverse(s.begin(), s.end());
        removeLeadingZeros(s);
        removeContinuousZeros(s);
        if(s.empty())
            return;
        auto head = s.begin();
        auto tail = head;
        while(tail != s.end()){
            if(*tail == ' '){
                reverse(head, tail);
                tail++;
                head = tail;
            }else{
                tail++;
            }
        }
        reverse(head, tail);
    }
};

class Solution {
public:
    void reverseWords(string &s) {
        vector<string> ss;
        string word;
        s += ' ';
        for(char& chr : s){
            if(chr != ' '){
                word += chr;
            }else{
                if(word.size() != 0){
                    ss.push_back(word);
                    word = "";
                }
            }
        }
        
        string result;
        for(int i = (int)ss.size() - 1; i >= 0; --i){
            result += (" " + ss[i]);
        }
        if(result.size() == 0){
            s = "";
        }else{
            s = result.substr(1, (int)result.size() - 1);
        }
    }
};

/*
int main(){
    string in = "  a  b  ";
    Solution2 ss;
    ss.reverseWords(in);
    cout << in << endl;
    return 0;
}
*/
