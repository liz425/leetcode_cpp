//
//  269_Alien_Dictionary.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 10/27/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution {
    //Some letter may not be in the graph, i.e. they do not have predecence relation with other letter
    //But they should be in the final result string. Since once a letter appears, it should be included.
public:
    vector<int> color;  //-1: not exist, 0: white, 1: gray, 2:black
    vector<vector<int>> graph;
    string result;
    Solution(){
        color = vector<int>(26, -1);
        graph = vector<vector<int>>(26);
        result = "";
    }
    string alienOrder(vector<string>& words) {
        //construct graph
        for(int i = 0; i < (int)words.size(); ++i){
            for(char ch : words[i])
                color[ch - 'a'] = 0;
            if(i > 0){
                int j = 0;
                while(j < words[i].size() && j < words[i - 1].size()){
                    if(words[i][j] != words[i - 1][j]){
                        graph[words[i - 1][j] - 'a'].push_back(words[i][j] - 'a');
                        //cout << words[i - 1][j] << " --> " << words[i][j] << endl;
                        break;
                    }
                    j++;
                }
                if(j == words[i].size() && words[i].size() < words[i - 1].size())    //words[i] is prefix of words[i-1]
                    return "";
            }
        }
        //DFS, topological sorting
        for(int i = 0; i < 26; ++i){
            if(color[i] == 0)
                if(!DFS(i))     //cycle
                    return "";
        }
        return result;
    }
    bool DFS(int k){
        //cout << char('a' + k) << endl;
        color[k] = 1;
        for(int i = 0; i < (int)graph[k].size(); ++i){
            if(color[graph[k][i]] == 0){
                if(!DFS(graph[k][i]))
                    return false;
            }else if(color[graph[k][i]] == 1){ //cycle
                return false;
            }
        }
        color[k] = 2;
        result = char('a' + k) + result;
        return true;
    }
};


/*
int main(void){
    Solution ss;
    vector<string> words = {"wrt","wrf","er","ett","rftt"};
    cout << ss.alienOrder(words) << endl;
}
*/
