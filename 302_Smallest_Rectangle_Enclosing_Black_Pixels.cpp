//
//  302_Smallest_Rectangle_Enclosing_Black_Pixels.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 12/6/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution2 {
    //Better use Solution1
public:
    enum direction {row, col};
    int minArea(vector<vector<char>>& image, int x, int y) {
        if(image.empty() || image[0].empty()){
            return 0;
        }
        int m = (int)image.size();
        int n = (int)image[0].size();
        auto check = [=](int index, direction drt) -> int{
            if(drt == row){
                for(int i = 0; i < n; ++i){
                    if(image[index][i] == '1'){
                        return 1;
                    }
                }
            }else{
                for(int i = 0; i < m; ++i){
                    if(image[i][index] == '1'){
                        return 1;
                    }
                }
            }
            return 0;
        };
        int left = find_first(0, y, check, col);
        int right = find_last(y, n - 1, check, col);
        int up = find_first(0, x, check, row);
        int down = find_last(x, m - 1, check, row);
        //cout << left << right << up << down << endl;
        return (right - left + 1) * (down - up + 1);
    }
    int find_first(int start, int end, function<int(int, direction)> check, direction drt){
        while(start < end){
            int mid = start + (end - start) / 2;
            if(check(mid, drt) == 0){
                start = mid + 1;
            }else{
                end = mid;
            }
        }
        return start;
    }
    int find_last(int start, int end, function<int(int, direction)> check, direction drt){
        while(start < end){
            int mid = end - (end - start) / 2;
            if(check(mid, drt) == 0){
                end = mid - 1;
            }else{
                start = mid;
            }
        }
        return end;
    }
};



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
    //Use [lo, hi) to do the binary search, this is basically the same idea with c++_STL::binary_search
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
    Solution2 ss;
    vector<vector<char>> image = {{'0','0','1','0'},{'0','1','1','0'},{'0','1','0','0'}};
    cout << ss.minArea(image, 0, 1) << endl;
}
*/
