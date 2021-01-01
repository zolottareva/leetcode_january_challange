//
//  main.cpp
//  leetcode_january1
//
//  Created by Золотарева Марина Олеговна on 01.01.2021.
//

//You are given an array of distinct integers arr and an array of integer arrays pieces, where the integers in pieces
//are distinct. Your goal is to form arr by concatenating the arrays in pieces in any order. However, you are not
//allowed to reorder the integers in each array pieces[i].
//Return true if it is possible to form the array arr from pieces. Otherwise, return false.

// Conclusions:
// found it difficult to understand task at first (took about 10 minutes to understand)
// whole task was done in less than an hour (including coffee brake:))

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int countMatches = 0;
        for (auto piece: pieces){
            int currentPosition = 0;
            while(currentPosition != arr.size() && piece[0] != arr[currentPosition]) { currentPosition++; }
            if(currentPosition != arr.size()){
                for (auto element: piece) {
                    if(element == arr[currentPosition]) {
                        countMatches++;
                        currentPosition++;
                    }
                    else return false;
                }
            }
            else return false;
        }
        if (countMatches == arr.size()) return true;
        else return false;
    }
};
int main() {
    return 0;
}
