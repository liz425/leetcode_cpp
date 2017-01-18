//
//  418_Sentence_Screen_Fitting.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 1/3/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"

class Solution3 {
    //Finding cycles in rows, same idea with:
    //https://discuss.leetcode.com/topic/68947/99-0ms-o-n-c-solution-where-n-words-detailed-explanation-and-analysis-included/2
    //T = O(n)
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = (int)sentence.size();
        vector<int> lens(n, 0);
        int sum = 0;
        for(int i = 0; i < n; ++i){
            lens[i] = (int)sentence[i].size();
            sum += lens[i] + 1;
            if(lens[i] > cols){
                //single word that cann't be placed into a line
                return 0;
            }
        }
        vector<int> cnts(n, 0);
        vector<int> next(n, 0);
        int cnt = rows * (cols / sum);
        cols = cols % sum;
        int remain = cols;
        int index = 0;
        for(int i = 0; i < n; ++i){
            if(i > 0){
                cnts[i] = cnts[i - 1] - 1;
            }
            while(remain >= lens[index]){
                remain -= (lens[index] + 1);
                index = (index + 1) % n;
                cnts[i]++;
            }
            next[i] = index;
            remain += lens[i] + 1;
        }
        //visited[], record whether current word has been placed in the row head, for the purpose of finding cycles
        vector<int> visited(n, -1);
        int cycleStart = 0, cycleLen = 0;
        int start = 0, i = 0;
        while(visited[start] == -1){
            visited[start] = i++;
            start = next[start];
        }
        cycleStart = visited[start];    //index 0-base
        cycleLen = i - cycleStart;
        
        int wordCnt = 0;
        if(rows > cycleStart){
            //count nums of words in each cycle
            int wordStart = start;
            int cycleWordCnt = 0;
            do{
                cycleWordCnt += cnts[start];
                start = next[start];
            }while(start != wordStart);
            int cycleNums = (rows - cycleStart) / cycleLen;
            wordCnt += cycleWordCnt * cycleNums;
            rows = cycleStart + (rows - cycleStart) % cycleLen;
        }
        
        start = 0;
        for(int i = 0; i < rows; ++i){
            wordCnt += cnts[start];
            start = next[start];
        }
        cnt += wordCnt / n;
        return cnt;
    }
};




class Solution2 {
    //Using sliding window to determine how many words can be fitted into a single row when start from different word. Time reduce from O(n^2) to O(n)
    //T = O(n + rows)
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = (int)sentence.size();
        vector<int> lens(n, 0);
        int sum = 0;
        for(int i = 0; i < n; ++i){
            lens[i] = (int)sentence[i].size();
            sum += lens[i] + 1;
            if(lens[i] > cols){
                //single word that cann't be placed into a line
                return 0;
            }
        }
        vector<int> cnts(n, 0);
        vector<int> next(n, 0);
        int cnt = rows * (cols / sum);
        cols = cols % sum;
        int remain = cols;
        int index = 0;
        //use sliding window to determine cnts[]
        for(int i = 0; i < n; ++i){
            if(i > 0){
                cnts[i] = cnts[i - 1] - 1;
            }
            while(remain >= lens[index]){
                remain -= (lens[index] + 1);
                index = (index + 1) % n;
                cnts[i]++;
            }
            next[i] = index;
            remain += lens[i] + 1;
        }
        int start = 0;
        int wordCnt = 0;
        for(int i = 0; i < rows; ++i){
            wordCnt += cnts[start];
            start = next[start];
        }
        cnt += wordCnt / n;
        return cnt;
    }
};



class Solution {
    // T = O(n^2 + rows)
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = (int)sentence.size();
        vector<int> lens(n, 0);
        int sum = 0;
        for(int i = 0; i < n; ++i){
            lens[i] = (int)sentence[i].size();
            sum += lens[i] + 1;
            if(lens[i] > cols){
                //single word that cann't be placed into a line
                return 0;
            }
        }
        vector<int> cnts(n, 0);
        vector<int> next(n, 0);
        int cnt = rows * (cols / sum);
        cols = cols % sum;
        for(int i = 0; i < n; ++i){
            int index = i;
            int remain = cols;
            while(remain >= lens[index]){
                remain -= (lens[index] + 1);
                index = (index + 1) % n;
                cnts[i]++;
            }
            next[i] = index;
        }
        int start = 0;
        int wordCnt = 0;
        for(int i = 0; i < rows; ++i){
            wordCnt += cnts[start];
            start = next[start];
        }
        cnt += wordCnt / n;
        return cnt;
    }
};

/*
int main(void){
    Solution ss;
    vector<string> sentence{"hello", "world"};
    int rows = 2, cols = 8;
    ss.wordsTyping(sentence, rows, cols);
}
*/
