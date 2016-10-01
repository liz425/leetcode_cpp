//
//  378_Kth_Smallest_Element_in_a_Sorted_Matrix.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 9/30/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
public:
    //use minHeap to store current value of each line.
    //heap initialized to be the first row of the matrix, namely the set of min value of each line.
    //When pop out min value of the heap, suppose in the p-th line, push the next value in the same line (p-th)
    struct comparator{
        bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
            return a.first > b.first;
        }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, comparator> heap;
        for(int i = 0; i < matrix[0].size(); ++i){
            heap.push(make_pair(matrix[0][i], make_pair(0, i)));
        }
        pair<int, pair<int, int>> small;
        for(int i = 0; i < k; ++i){
            small = heap.top();
            int x = small.second.first;
            int y = small.second.second;
            heap.pop();
            if(x < matrix.size() - 1)
                heap.push(make_pair(matrix[x+1][y], make_pair(x+1, y)));
        }
        return small.first;
    }
};
