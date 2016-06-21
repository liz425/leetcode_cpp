//
//  085_Maximal_Rectangle.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 6/16/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"

class Solution4 {
public:
    //DP solution, at matrix[i][j], calculate rectangle with height[i][j]
    //If at matrix[i-1][j], rectangle width is n, then at matrix[i][j], rectangle width is no lager than n;
    //solve the problem row by row.
    int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.empty()) return 0;
        const int m = (int)matrix.size();
        const int n = (int)matrix[0].size();
        int left[n], right[n], height[n];
        fill_n(left,n,0); fill_n(right,n,n); fill_n(height,n,0);
        int maxA = 0;
        for(int i=0; i<m; i++) {
            int cur_left=0, cur_right=n;
            for(int j=0; j<n; j++) { // compute height (can do this from either side)
                if(matrix[i][j]=='1') height[j]++;
                else height[j]=0;
            }
            for(int j=0; j<n; j++) { // compute left (from left to right)
                if(matrix[i][j]=='1') left[j]=max(left[j],cur_left);
                else {left[j]=0; cur_left=j+1;}
            }
            // compute right (from right to left)
            for(int j=n-1; j>=0; j--) {
                if(matrix[i][j]=='1') right[j]=min(right[j],cur_right);
                else {right[j]=n; cur_right=j;}
            }
            // compute the area of rectangle (can do this from either side)
            for(int j=0; j<n; j++)
                maxA = max(maxA,(right[j]-left[j])*height[j]);
        }
        return maxA;
    }
    
};

class Solution3 {
public:
    //AC: 32ms
    //Use algorithm of "084_Largest_Rectangle_in_Histogram",
    //Choose either "largestRectangleArea" or "largestRectangleArea2", the second one run faster than the first one
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        //add a sentinal to the end of the vector
        heights.push_back(0);
        int len = (int)heights.size();
        int area_max = 0;
        for(int i = 0; i < len; ++i){
            while(!stk.empty() && heights[stk.top()] > heights[i]){
                int height = heights[stk.top()];
                stk.pop();
                int left = (stk.empty())? -1 : stk.top();
                int area_new = height * (i - left - 1);
                area_max = max(area_max, area_new);
            }
            stk.push(i);
        }
        return area_max;
    }
    
    int largestRectangleArea2(vector<int>& heights) {
        int n = (int)heights.size();
        int Area = 0;
        vector<int> left(n,0);
        vector<int> right(n,0);
        for(int i = 1; i < n; ++i){
            int j = i - 1;
            while(j >= 0 && heights[i] <= heights[j]){
                j -= (left[j] + 1);
            }
            left[i] = i - j - 1;  //starts from i, how far the rectangle can go toward left
        }
        for(int i = n - 2; i >= 0; --i){
            int j = i + 1;
            while(j < n && heights[i] <= heights[j]){
                j += (right[j] + 1);
            }
            right[i] = j - i - 1; //starts from i, how far the rectangle can go toward right
        }
        for(int i = 0; i < n; ++i){
            Area = max(Area, heights[i] * (right[i] + 1 + left[i])); //Bottom: left[i]+right[i]+1
        }
        return Area;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int height = (int)matrix.size();
        if(height == 0)
            return 0;
        int width = (int)matrix[0].size();
        vector<int> hist(width, 0);
        int max_area = 0;
        for(int i = 0; i < height; ++i){
            for(int j = 0; j < width; ++j){
                if(matrix[i][j] == '1'){
                    hist[j] += 1;
                }else{
                    hist[j] = 0;
                }
            }
            int temp = largestRectangleArea2(hist);
            max_area = max(temp, max_area);
        }
        return max_area;
    }
};



class Solution2 {
    //TLE... DO NOT use it.
    //Run much faster than first solution but still TLE.
public:
    struct coor{
        int x;
        int y;
        coor(int xin, int yin):x(xin), y(yin){};
    };
    
    struct corner{
        coor pos;
        int area;
        corner(coor posIn, int areaIn):pos(posIn), area(areaIn){};
    };
    
    struct node{
        vector<corner> corners = {};
        int maxArea = 0;
    };
    
    int maxArea = 0;
    int height = 0;
    int width = 0;
    
    bool illegal(coor pos){
        if(pos.x >= width || pos.x < 0 || pos.y >= height || pos.y < 0){
            return true;
        }else{
            return false;
        }
    }
    
    int area(coor top_left, coor bottom_right){
        if(illegal(top_left) || illegal(bottom_right) || top_left.x > bottom_right.x || top_left.y > bottom_right.y){
            return 0;
        }else{
            return (bottom_right.x - top_left.x + 1) * (bottom_right.y - top_left.y + 1);
        }
    }
    
    bool valid(coor p1, coor p2, vector<vector<char>>& matrix){
        for(int j = p1.y; j <= p2.y; ++j){
            for(int i = p1.x; i <= p2.x; ++i){
                if(matrix[j][i] == '0'){
                    return false;
                }
            }
        }
        return true;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        maxArea = 0;
        width = 0;
        height = (int)matrix.size();
        if(height == 0)
            return 0;
        width = (int)matrix[0].size();
        if(width == 0)
            return 0;
        vector<vector<node>> dp(height, vector<node>(width));
        node p0;
        
        for(int j = 0; j < height; ++j){
            for(int i = 0; i < width; ++i){
                if(matrix[j][i] == '0'){
                    continue;
                }
                
                node current;
                current.corners.push_back(corner(coor(i, j), 1));
                current.maxArea = 1;
                
                if(j > 0){
                    for(corner& pc : dp[j - 1][i].corners){
                        if(valid(coor(pc.pos.x, j), coor(i, j), matrix)){
                            int areaTmp = area(pc.pos, coor(i, j));
                            current.corners.push_back(corner(pc.pos, areaTmp));
                            current.maxArea = max(current.maxArea, areaTmp);
                        }
                    }
                }
                if(i > 0){
                    for(corner& pc : dp[j][i - 1].corners){
                        if(valid(coor(i, pc.pos.y), coor(i, j), matrix)){
                            int areaTmp = area(pc.pos, coor(i, j));
                            current.corners.push_back(corner(pc.pos, areaTmp));
                            current.maxArea = max(current.maxArea, areaTmp);
                        }
                    }
                }
                if(j > 0 && i > 0){
                    for(corner& pc : dp[j - 1][i - 1].corners){
                        if(valid(coor(i, pc.pos.y), coor(i, j), matrix) && valid(coor(pc.pos.x, j), coor(i, j), matrix)){
                            int areaTmp = area(pc.pos, coor(i, j));
                            current.corners.push_back(corner(pc.pos, areaTmp));
                            current.maxArea = max(current.maxArea, areaTmp);
                        }
                    }
                }
                
                //update global maxArea
                maxArea = max(maxArea, current.maxArea);
                dp[j][i] = current;
            }
        }
        return maxArea;
    }
};



class Solution {
    //TLE... DO NOT use it.
public:
    struct coor{
        int x;
        int y;
        coor(int xin, int yin):x(xin), y(yin){};
    };
    int maxArea = 0;
    int height = 0;
    int width = 0;
    
    bool illegal(coor pos){
        if(pos.x >= width || pos.x < 0 || pos.y >= height || pos.y < 0){
            return true;
        }else{
            return false;
        }
    }
    
    int area(coor top_left, coor bottom_right){
        if(illegal(top_left) || illegal(bottom_right) || top_left.x > bottom_right.x || top_left.y > bottom_right.y){
            return 0;
        }else{
            return (bottom_right.x - top_left.x + 1) * (bottom_right.y - top_left.y + 1);
        }
    }
    
    void partialMax(coor top_left, coor bottom_right, vector<vector<char>>& matrix){
        if(area(top_left, bottom_right) <= maxArea)
            return;
        bool found = false;
        int i = 0, j = 0;
        for(j = top_left.y; j <= bottom_right.y; ++j){
            for(i = top_left.x; i <= bottom_right.x; ++i){
                if(matrix[j][i] == '0'){
                    found = true;
                    break;
                }
            }
            if(found)   break;
        }
        if(!found){
            maxArea = area(top_left, bottom_right);
        }else{
            maxArea = max(maxArea, area(top_left, coor(bottom_right.x, j - 1)));
            partialMax(coor(top_left.x, j + 1), bottom_right, matrix);
            partialMax(top_left, coor(i - 1, bottom_right.y), matrix);
            partialMax(coor(i + 1, top_left.y), bottom_right, matrix);
        }
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        maxArea = 0;
        maxArea = 0;
        width = 0;
        height = 0;
        height = (int)matrix.size();
        if(height == 0)
            return 0;
        width = (int)matrix[0].size();
        partialMax(coor(0, 0), coor(width - 1, height - 1), matrix);
        return maxArea;
    }
};


/*
int main(){
    Solution4 ss;
    vector<string> input =  {"1111111111111101001111111100111011111111","1111011011111111101101111101111111111111","0111101011111101101101101111111111111111","0101101011111111111101111111010110111111","1111111111110111110110010111111111111111","1111111110110101111111111101011111101111","0110110101110011111111111111110111110101","0111111111111100111111100110011011010101","1111011110111111111011011011110101101011","1111111110111111111101101101110111101111","1110110011111111111100111111111111111111","1011111110111101111001110111111111111111","0110111111111111101111110111011111011111","1111111111111111011111111111110111111011","1111100111111110101100111111111111101111","1111101111111110111111011111111111011111","1111101111111111111111011001111110011111","1111110111111111011111111111110111110111","1011111111111111010111110010111110111111","1111110011111111111110111111111111111011","1111111111111111110111011111011111011011","1100011011111111111111011111011111111111","1111101011111111111101100101110011111111","1110010111111111111011011110111101111101","1111111111111101101111111111101111111111","1111111011111101111011111111111110111111","1110011111111110111011111111110111110111","1111111111111100111111010111111111110111","1111111111111111111111000111111111011101","1111110111111111111111111101100111011011","1111011011111101101101111110111111101111","1111111111011111111111111111111111111111","1111111111111111111111111111111111111111","1100011111111110111111111111101111111011","1111101111111101111010111111111111111111","0111111111110011111111110101011011111111","1011011111101111111111101111111111110011","1010111111111111111111111111111110011111","0111101111011111111111111111110111111111","0111111011111111011101111011101111111111","0111111111110101111011111101011001111011","1111111111111011110111111101111111101110","1111101111111100111111111110111111001111","1101101111110101111101111111100111010100","0110111111100111110010111110111011011101"};
    
    
    vector<string> input2 = {
    "1000101",
    "1111101",
    "0111011",
    "0110111",
    "1110000"};
    
    vector<string> input3 = {"1111111111111101001111111100111011111111","1111011011111111101101111101111111111111","0111101011111101101101101111111111111111","0101101011111111111101111111010110111111","1111111111110111110110010111111111111111","1111111110110101111111111101011111101111","0110110101110011111111111111110111110101","0111111111111100111111100110011011010101","1111011110111111111011011011110101101011","1111111110111111111101101101110111101111","1110110011111111111100111111111111111111","1011111110111101111001110111111111111111","0110111111111111101111110111011111011111","1111111111111111011111111111110111111011","1111100111111110101100111111111111101111","1111101111111110111111011111111111011111","1111101111111111111111011001111110011111","1111110111111111011111111111110111110111","1011111111111111010111110010111110111111","1111110011111111111110111111111111111011","1111111111111111110111011111011111011011","1100011011111111111111011111011111111111","1111101011111111111101100101110011111111","1110010111111111111011011110111101111101","1111111111111101101111111111101111111111","1111111011111101111011111111111110111111","1110011111111110111011111111110111110111","1111111111111100111111010111111111110111","1111111111111111111111000111111111011101","1111110111111111111111111101100111011011","1111011011111101101101111110111111101111","1111111111011111111111111111111111111111","1111111111111111111111111111111111111111","1100011111111110111111111111101111111011","1111101111111101111010111111111111111111","0111111111110011111111110101011011111111","1011011111101111111111101111111111110011","1010111111111111111111111111111110011111","0111101111011111111111111111110111111111"};
    
    vector<vector<char>> matrix;
    for(string& s : input){
        vector<char> new_vec;
        for(char& ch : s){
            new_vec.push_back(ch);
        }
        matrix.push_back(new_vec);
    }
    
    
    clock_t start, end;
    start = clock();
    int result = ss.maximalRectangle(matrix);
    end = clock();
    cout << result << endl;
    double time_consumed = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    cout << time_consumed << endl;
 
}
 */
