//
//  418_Sentence_Screen_Fitting.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 1/3/17.
//  Copyright © 2017 zl. All rights reserved.
//

#include "inc.h"


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
