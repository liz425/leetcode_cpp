//
//  407_Trapping_Rain_Water_II.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/8/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    struct comparator{
        bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
            return a.first > b.first;
        }
    };
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.empty() || heightMap[0].empty())
            return 0;
        int m = (int)heightMap.size();
        int n = (int)heightMap[0].size();
        int sum = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, comparator> heap;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        //add border to heap
        for(int i = 0; i < n; ++i){
            visited[0][i] = true;
            heap.push(make_pair(heightMap[0][i], make_pair(0, i)));
            visited[m-1][i] = true;
            heap.push(make_pair(heightMap[m-1][i], make_pair(m-1, i)));
        }
        for(int i = 1; i < m - 1; ++i){
            visited[i][0] = true;
            heap.push(make_pair(heightMap[i][0], make_pair(i, 0)));
            visited[i][n-1] = true;
            heap.push(make_pair(heightMap[i][n-1], make_pair(i, n-1)));
        }
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        //every node in map will push-in and pop-out once
        while(!heap.empty()){
            auto shortest = heap.top();
            heap.pop();
            int vol = shortest.first;
            for(int i = 0; i < 4; ++i){
                int x = shortest.second.first + dx[i];
                int y = shortest.second.second + dy[i];
                if(x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]){
                    heap.push(make_pair(max(vol, heightMap[x][y]), make_pair(x, y)));
                    sum += max(vol - heightMap[x][y], 0);
                    visited[x][y] = true;
                }
            }
        }
        return sum;
    }
};
