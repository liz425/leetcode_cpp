//
//  Word_Search.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 7/8/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    int height, width;
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() == 0){
            return true;
        }
        height = (int)board.size();
        if(height == 0){
            return false;
        }
        width = (int)board[0].size();
        vector<vector<bool>> visited(height, vector<bool>(width, false));
        for(int j = 0; j < height; ++j){
            for(int i = 0; i < width; ++i){
                if(board[j][i] == word[0]){
                    visited[j][i] = true;
                    if(DFS(board, word.substr(1), visited, i, j)){
                        return true;
                    }else{
                        visited[j][i] = false;
                    }
                }
            }
        }
        return false;
    }
    bool DFS(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int i, int j){
        if(word.size() == 0){
            return true;
        }
        if(i < width - 1 && visited[j][i + 1] == false && board[j][i + 1] == word[0]){
            visited[j][i + 1] = true;
            if(DFS(board, word.substr(1), visited, i + 1, j)){
                return true;
            }else{
                visited[j][i + 1] = false;
            }
        }
        if(i > 0 && visited[j][i - 1] == false && board[j][i - 1] == word[0]){
            visited[j][i - 1] = true;
            if(DFS(board, word.substr(1), visited, i - 1, j)){
                return true;
            }else{
                visited[j][i - 1] = false;
            }
        }
        if(j < height - 1 && visited[j + 1][i] == false && board[j + 1][i] == word[0]){
            visited[j + 1][i] = true;
            if(DFS(board, word.substr(1), visited, i, j + 1)){
                return true;
            }else{
                visited[j + 1][i] = false;
            }
        }
        if(j > 0 && visited[j - 1][i] == false && board[j - 1][i] == word[0]){
            visited[j - 1][i] = true;
            if(DFS(board, word.substr(1), visited, i, j - 1)){
                return true;
            }else{
                visited[j - 1][i] = false;
            }
        }
        return false;
    }
};