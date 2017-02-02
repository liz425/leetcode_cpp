//
//  318_Maximum_Product_of_Word_Lengths.cpp
//  leetcode_cpp
//
//  Created by 李镇 on 2/26/16.
//  Copyright © 2016 zl. All rights reserved.
//

#include "inc.h"


class Solution2 {
    //NOTICE: '==' has higher precedence than '&'  !!!!!!
public:
    int maxProduct(vector<string>& words) {
        vector<unsigned int> masks;
        for(string& word : words){
            masks.push_back(genMask(word));
        }
        int maxProd = 0, n = (int)words.size();
        for(int i = 0; i < n - 1; ++i){
            for(int j = i + 1; j < n; ++j){
                //cout << masks[i] << "  " << masks[j] << endl;
                if((masks[i] & masks[j]) == 0){
                    maxProd = max(maxProd, int(words[i].size() * words[j].size()));
                }
            }
        }
        return maxProd;
    }
    unsigned int genMask(string word){
        unsigned int result = 0;
        for(char ch : word){
            result |= 1 << int(ch - 'a');
            if(result == 0x3ffffff){
                break;
            }
        }
        return result;
    }
};


class Solution {
public:
  int maxProduct(vector<string>& words) {
    vector <unsigned int> bits;
    for(string &ss: words){
      unsigned bitrepr = 0;
      for(string::iterator it = ss.begin(); it < ss.end(); it++){
        int shift = *it - 'a';
        bitrepr |= 0x1 << shift;
      }
      bits.push_back(bitrepr);
    }
    int maxP = 0;
    int k = (int)words.size();
    for(int i = 0; i < k - 1; i++){
      for(int j = i + 1; j < k; j++){
        if((bits[i] & bits[j]) == 0){
          int lens = int(words[i].length() * words[j].length());
          maxP = (lens > maxP)? lens : maxP;
        }
      }
    }
    return maxP;
  }
};

//int main(void){
//  vector<string> words = {};
//  Solution ss;
//  cout << ss.maxProduct(words) << endl;
//  int a =0;
//}

