//
//  240_Search_a_2D_Matrix||.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 7/19/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = (int)matrix.size();
        if(m == 0)
            return false;
        int n = (int)matrix[0].size();
        int i = 0, j = n - 1;
        while(i < m && j >= 0){
            if(matrix[i][j] > target){
                --j;
            }else if(matrix[i][j] < target){
                ++i;
            }else{
                return true;
            }
        }
        return false;
    }
};



class Solution {
    //Run slowly, NOT a good solution
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        int height = int(matrix.size());
        if(matrix[0].empty())
            return false;
        int width = int(matrix[0].size());
        return helper(matrix, 0, 0, width, height, target);
    }
    bool helper(vector<vector<int>>& matrix, int startX, int startY, int endX, int endY, int target){
        if(startX >= endX || startY >= endY)
            return false;
        if(target > matrix[endY - 1][endX - 1] || target < matrix[startY][startX])
            return false;
        int W = endX - startX;
        int H = endY - startY;
        int rank = min(W, H);
        int low = 0, high = min(W, H) - 1;
        int mid = (low + high) / 2;
        while(low <= high){
            if(matrix[startY + H * mid / rank][startX + W * mid / rank] == target)
                return true;
            else if(matrix[startY + H * mid / rank][startX + W * mid / rank] < target){
                low = mid + 1;
                mid = (low + high) / 2;
            }else{
                high = mid - 1;
                mid = (low + high) / 2;
            }
        }
        if(helper(matrix, startX + W * high / rank + 1, startY, endX, startY + H * low / rank, target))
            return true;
        if(helper(matrix, startX, startY + H * high / rank + 1, startX + W * low / rank, endY, target))
            return true;
        return false;
    }
};

/*
int main(){
    Solution2 ss;
    vector<vector<int>> matrix = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}};
    for(auto items : matrix){
        for(auto target : items){
            cout << ss.searchMatrix(matrix, target);
        }
        cout << endl;
    }
}
 */

