//
//  305_Number_of_Islands_II.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/3/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    //union-find
public:
    int num;
    vector<int> father;
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> ans;
        father = vector<int>(m * n, -1);
        for(auto position : positions){
            int p = position.first;
            int q = position.second;
            father[p * n + q] = p * n + q;
            num++;
            if(p > 0 && father[(p-1)*n+q] != -1)
                un(p*n+q, (p-1)*n+q);
            if(p < m - 1 && father[(p+1)*n+q] != -1)
                un(p*n+q, (p+1)*n+q);
            if(q > 0 && father[p*n+q-1] != -1)
                un(p*n+q, p*n+q-1);
            if(q < n - 1 && father[p*n+q+1] != -1)
                un(p*n+q, p*n+q+1);
            ans.push_back(num);
        }
        return ans;
    }
    int compressed_find(int k){
        int son = k;
        while(father[son] != son){
            son = father[son];
        }
        int ancestor = son;
        son = k;
        while(father[son] != son){
            int parent = father[son];
            father[son] = ancestor;
            son = parent;
        }
        return ancestor;
    }
    
    //union is a reserved type in c++
    void un(int p, int q){
        int father_p = compressed_find(p);
        int father_q = compressed_find(q);
        if(father_p != father_q){
            father[father_p] = father_q;
            num--;
        }
    }
};
