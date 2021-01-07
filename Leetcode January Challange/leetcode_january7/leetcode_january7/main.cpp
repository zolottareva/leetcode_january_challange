//
//  main.cpp
//  leetcode_january7
//
//  Created by Золотарева Марина Олеговна on 07.01.2021.
//

#include <iostream>
#include <string>
#include <unordered_map>

using std::unordered_map;
using std::string;

int lengthOfLongestSubstring(string s) {
    int max_length = 0;
    int current_length = 0;
    unordered_map <char, size_t> symbolToPreviousPosition;
    size_t stringSize = s.size();
    for(size_t position = 0; position < stringSize; position++){
        if(symbolToPreviousPosition.count(s[position]) == 0){
            current_length++;
        }
        else{
            max_length = std::max(current_length,max_length);
            current_length = 1;
            position = symbolToPreviousPosition[s[position]];
            symbolToPreviousPosition.clear();
        }
        symbolToPreviousPosition[s[position]] = position + 1;
    }
    return std::max(current_length,max_length);
}
int main() {
    std::cout << lengthOfLongestSubstring("abcdefg") << std::endl;
    return 0;
}
