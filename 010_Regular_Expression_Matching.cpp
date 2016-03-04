//
//  010_Regular_Expression_Matching.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 1/21/16.
//  Copyright © 2016 zl. All rights reserved.
//

//////////////////////////////////////////////////
// This code seems right when running on my machine
// But it encounter "Runtime Error" in the leetcode
// Have no idea why it happens.
//////////////////////////////////////////////////


#include <string>
using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {
    if ((s.length() == 0)&&(p.length() == 0)) {
      return true;
    }
    
    if(p.back() == '*'){
      string p1 = p;
      p1.pop_back();
      char c_p = p1.back();
      p1.pop_back();
      
      string s1 = s;
      char c_s = s1.back();
      s1.pop_back();
      
      if(this->isMatch(s, p1))
        return true;
      else if(this->CharEqual(c_p, c_s)){
        if(this->isMatch(s1, p1))
          return true;
        else
          return this->isMatch(s1, p);
      }
      else
        return false;
    }
    else if (this->CharEqual(s.back(), p.back())) {
      s.pop_back();
      p.pop_back();
      return this->isMatch(s, p);
    }
    else{
      return false;
    }
  }
  
  bool CharEqual(char a, char b){
    if (a == '.' || b == '.' || a == b) {
      return true;
    }
    else
      return false;
  }
};