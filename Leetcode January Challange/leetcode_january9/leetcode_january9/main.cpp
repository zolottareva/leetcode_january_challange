//
//  main.cpp
//  leetcode_january9
//
//  Created by Золотарева Марина Олеговна on 09.01.2021.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

using std:: vector;
using std:: string;
using std:: unordered_set;
using std:: queue;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    
       unordered_set<string> words;
       for(auto element: wordList){
           words.insert(element);
       }
    
       if(words.find(endWord) == words.end())
           return 0;
    
       queue<string> bfsQueue;
       int level = 0;
       bfsQueue.push(beginWord);
       while(!bfsQueue.empty()){
           level++;
           int lsize = bfsQueue.size();
           while(lsize--)
           {
               string current = bfsQueue.front();
               size_t currentLength = current.length();
               bfsQueue.pop();
               for(int i = 0; i < currentLength; i++)
               {
                   string temp = current;
                   for(char x = 'a'; x <= 'z'; x++)
                   {
                       temp[i] = x;
                       if(temp.compare(current) == 0)
                           continue;
                       if(temp.compare(endWord) == 0)
                       {
                           return level + 1;
                       }
                       if(words.find(temp) != words.end())
                       {
                           bfsQueue.push(temp);
                           words.erase(temp);
                       }
                   }
               }
           }
       }
       return 0;
   }
int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    std::cout << ladderLength(beginWord, endWord, wordList) << std::endl;
    return 0;
}
