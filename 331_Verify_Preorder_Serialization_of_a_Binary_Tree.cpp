//
//  331_Verify_Preorder_Serialization_of_a_Binary_Tree.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 7/28/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
    //Brillant solution from discussion.
    //NO recurrsion nor stack.
    //"slots" is the number of nodes avaliable to be added to the current tree.
    //It's the similar idea of "outdegree - indegree" in a tree.
public:
    bool isValidSerialization(string preorder) {
        preorder += ',';
        string item = "";
        int slots = 1;
        for(char& ch : preorder){
            if(ch != ','){
                item += ch;
            }else{
                if(--slots < 0)
                    return false;
                if(item != "#")
                    slots += 2;
                item = "";
            }
        }
        return !slots;
    }
};

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<int> s;
        bool traversaled = false;
        preorder += ',';
        string item = "";
        for(char& ch : preorder){
            if(ch != ','){
                item += ch;
            }else{
                if(s.empty()){
                    if(traversaled)
                        return false;
                    else
                        traversaled = true;
                }if(item == "#"){
                    while(!s.empty() && s.top() == 1){
                        s.pop();
                    }
                    if(!s.empty() && s.top() == 0){
                        s.pop();
                        s.push(1);
                    }
                    item = "";
                }else{
                    s.push(0);
                    item = "";
                }
            }
        }
        return s.empty();
    }
};

/*
int main(){
    Solution ss;
    cout << ss.isValidSerialization("9,3,4,#,#,1,#,2,#,6,#,#") << endl;
}
*/
