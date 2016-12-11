//
//  302_Smallest_Rectangle_Enclosing_Black_Pixels.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/6/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    //Idea from Stefan
    //Binary search at one direction, T = O(m*logn + n*logm)
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = (int)image.size();
        int n = (int)image[0].size();
        auto searchVertical = [=](int idx) -> int{
            for(int i = 0; i < m; ++i){
                if(image[i][idx] == '1'){
                    return 1;
                }
            }
            return 0;
        };
        auto searchHorizontal = [=](int idx) -> int{
            for(int i = 0; i < n; ++i){
                if(image[idx][i] == '1'){
                    return 1;
                }
            }
            return 0;
        };
        
        int left = first(0, y, 1, searchVertical);
        int right = first(y, n , 0, searchVertical);
        int up = first(0, x, 1, searchHorizontal);
        int down = first(x, m, 0, searchHorizontal);
        
        return (right - left) * (down - up);
    }
    
    //find the first target in range [lo, hi)
    int first(int lo, int hi, int target, function<int(int)> search){
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            if(search(mid) == target){
                hi = mid;
            }else{
                lo = mid + 1;
            }
        }
        return lo;
    }
};


/*
int main(void){
    Solution ss;
    vector<vector<char>> image = {{'0','0','1','0'},{'0','1','1','0'},{'0','1','0','0'}};
    cout << ss.minArea(image, 0, 1) << endl;
}
*/
