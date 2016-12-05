//
//  Google_OA2.cpp
//  leetcode_cpp
//
//  Created by Zhen Li on 11/26/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include <string>
#include <stack>
#include <set>
#include <iostream>
using namespace std;


//sum of paths contain at least one image, solution2
//remember to module if necessary
int solution2(string &S) {
    //for easier processing the last file/path
    S += '\n';
    //pair<path_lens, marked>. If already contained image file, mark it.
    //path format: start with "/", end without slash
    stack<pair<int, bool>> paths;
    int spaceCnt = 0;
    string buf = "";
    bool isFile = false;
    int sum = 0;
    set<string> extensions = {".jpeg", ".png", ".gif"};
    //push root as sentinal, stack never be empty
    paths.push(make_pair(0, false));
    for(char ch : S){
        if(ch == '\n'){
            if(isFile){
                if(extensions.find(buf) != extensions.end() && !paths.top().second){
                    //found image file
                    //if in root, lens should be 1 rather than 0
                    sum += (paths.top().first == 0)? 1 : paths.top().first;
                    paths.top().second = true;
                }
            }else{
                paths.push(make_pair(paths.top().first + (int)buf.size() + 1, false));
            }
            spaceCnt = 0;
            buf = "";
            isFile = false;
        }else if(ch == ' '){
            spaceCnt++;
        }else{
            //minus 1 since we have sentinal in the bottom of stack
            //spaceCnt smaller: changed into parent dirs
            while(paths.size() - 1 > spaceCnt){
                paths.pop();
            }
            if(ch == '.'){
                //is file, clear extension
                isFile = true;
                buf = "";
            }
            buf += ch;
        }
    }
    return sum;
}



//sum of images
//remember to module if necessary
int solution3(string &S) {
    //for easier processing the last file/path
    S += '\n';
    //path format: start with "/", end without slash
    stack<int> paths;   //each path lens
    int spaceCnt = 0;
    string buf = "";    //store dir or file name
    string extBuf = ""; //store file extension
    bool isFile = false;
    int sum = 0;
    paths.push(0);  //add sentinal, paths never be empty
    set<string> extensions = {".jpeg", ".png", ".gif"};
    for(char ch : S){
        if(ch == '\n'){
            if(isFile){
                if(extensions.find(extBuf) != extensions.end()){
                    //found image file
                    sum += paths.top() + (int)buf.size() + 1;
                }
            }else{
                paths.push(paths.top() + (int)buf.size() + 1);
            }
            spaceCnt = 0;
            buf = "";
            extBuf = "";
            isFile = false;
        }else if(ch == ' '){
            spaceCnt++;
        }else{
            //minus 1 since we have sentinal in stack
            //spaceCnt smaller: changed into parent dirs
            while(paths.size() - 1 > spaceCnt){
                paths.pop();
            }
            if(ch == '.'){
                //is file, clear extension
                isFile = true;
                extBuf = "";
            }
            extBuf += ch;
            buf += ch;
        }
    }
    return sum;
}


//longest image
//remember to module if necessary
int solution4(string &S) {
    //for easier processing the last file/path
    S += '\n';
    //path format: start with "/", end without slash
    stack<int> paths;   //each path lens
    int spaceCnt = 0;
    string buf = "";    //store dir or file name
    string extBuf = ""; //store file extension
    bool isFile = false;
    int maxLen = 0;
    paths.push(0);  //add sentinal, paths never be empty
    set<string> extensions = {".jpeg", ".png", ".gif"};
    for(char ch : S){
        if(ch == '\n'){
            if(isFile){
                if(extensions.find(extBuf) != extensions.end()){
                    //found image file
                    maxLen = max(maxLen, paths.top() + (int)buf.size() + 1);
                }
            }else{
                paths.push(paths.top() + (int)buf.size() + 1);
            }
            spaceCnt = 0;
            buf = "";
            extBuf = "";
            isFile = false;
        }else if(ch == ' '){
            spaceCnt++;
        }else{
            //minus 1 since we have sentinal in stack
            //spaceCnt smaller: changed into parent dirs
            while(paths.size() - 1 > spaceCnt){
                paths.pop();
            }
            if(ch == '.'){
                //is file, clear extension
                isFile = true;
                extBuf = "";
            }
            extBuf += ch;
            buf += ch;
        }
    }
    return maxLen;
}


//longest path contains image
//remember to module if necessary
int solution5(string &S) {
    //for easier processing the last file/path
    S += '\n';
    //path format: start with "/", end without slash
    stack<int> paths;   //each path lens
    int spaceCnt = 0;
    string buf = "";    //store dir or file extension
    bool isFile = false;
    int maxLen = 0;
    paths.push(0);  //add sentinal, paths never be empty
    set<string> extensions = {".jpeg", ".png", ".gif"};
    for(char ch : S){
        if(ch == '\n'){
            if(isFile){
                if(extensions.find(buf) != extensions.end()){
                    //found image file
                    //if in root, lens should be 1 rather than 0
                    int pathLen = (paths.top() == 0)? 1 : paths.top();
                    maxLen = max(maxLen, pathLen);
                }
            }else{
                paths.push(paths.top() + (int)buf.size() + 1);
            }
            spaceCnt = 0;
            buf = "";
            isFile = false;
        }else if(ch == ' '){
            spaceCnt++;
        }else{
            //minus 1 since we have sentinal in stack
            //spaceCnt smaller: changed into parent dirs
            while(paths.size() - 1 > spaceCnt){
                paths.pop();
            }
            if(ch == '.'){
                //is file, clear extension
                isFile = true;
                buf = "";
            }
            buf += ch;
        }
    }
    return maxLen;
}


/*
int main(void){
    //paths sum = 18, images sum = 60
    string S = "a\n ab\n  c.jpeg\n  x\n   y.png\n  d.png\n ef\n  h.gif\ni.jpeg\nk.png";
    string SS = "a.jpeg\nb.png";
    cout << solution5(S) << endl;
}
*/
