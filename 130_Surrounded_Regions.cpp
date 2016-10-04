//
//  130_Surrounded_Regions.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/3/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    //Use BFS, T = O(n^2)
    //Also we can use Union-find
    //For the BFS method, we can have a better solution (less memory): instead of allocated a new matrix 'visited'
    //We could utilize the original board as follow:
    //BFS the boarders, set every 'O' and it's direct or indirect neibors as '1' (means these are escaped)
    //After that, turn all other 'O' to 'X'
    //Finally, turn '1' back to 'O'
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty())
            return;
        int m = (int)board.size();
        int n = (int)board[0].size();
        queue<int> escaped;
        vector<int> visited(m * n, 0);  //0:unvisited, 1:visted && escapded -1:visted but not escaped
        //initial for boarders
        for(int i = 0; i < n; ++i){
            if(board[0][i] == 'O'){
                escaped.push(i);
                visited[i] = 1;
            }else{
                visited[i] = -1;
            }
            if(board[m-1][i] == 'O'){
                escaped.push((m-1)*n+i);
                visited[(m-1)*n+i] = 1;
            }else{
                visited[(m-1)*n+i] = -1;
            }
        }
        for(int i = 1; i < m - 1; ++i){
            if(board[i][0] == 'O'){
                escaped.push(i*n);
                visited[i*n] = 1;
            }else{
                visited[i*n] = -1;
            }
            if(board[i][n-1] == 'O'){
                escaped.push(i*n + n-1);
                visited[i*n + n-1] = 1;
            }else{
                visited[i*n + n-1] = -1;
            }
        }
        //BFS
        while(!escaped.empty()){
            int cur = escaped.front();
            escaped.pop();
            int i = cur / n;
            int j = cur % n;
            if(i > 0 && visited[(i-1)*n+j] == 0){
                if(board[i-1][j] == 'O'){
                    visited[(i-1)*n+j] = 1;
                    escaped.push((i-1)*n+j);
                }else{
                    visited[(i-1)*n+j] = -1;
                }
            }
            if(i < m - 1 && visited[(i+1)*n+j] == 0){
                if(board[i+1][j] == 'O'){
                    visited[(i+1)*n+j] = 1;
                    escaped.push((i+1)*n+j);
                }else{
                    visited[(i+1)*n+j] = -1;
                }
            }
            if(j > 0 && visited[i*n+j-1] == 0){
                if(board[i][j-1] == 'O'){
                    visited[i*n+j-1] = 1;
                    escaped.push(i*n+j-1);
                }else{
                    visited[i*n+j-1] = -1;
                }
            }
            if(j < n - 1 && visited[i*n+j+1] == 0){
                if(board[i][j+1] == 'O'){
                    visited[i*n+j+1] = 1;
                    escaped.push(i*n+j+1);
                }else{
                    visited[i*n+j+1] = -1;
                }
            }
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(visited[i*n+j] != 1)
                    board[i][j] = 'X';
            }
        }
        return;
    }
};

/*
int main(void){
    Solution ss;
    vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    ss.solve(board);
    int m = (int)board.size();
    int n = (int)board[0].size();
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
*/
