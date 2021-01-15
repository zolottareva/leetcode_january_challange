//
//  main.cpp
//  leetcode_january15
//
//  Created by Золотарева Марина Олеговна on 15.01.2021.
//

#include <iostream>
#include <vector>

using std::vector;
void printVector(const vector <int>& vec){
    for(auto element: vec){
        std:: cout << element << " ";
    }
    std::cout << std::endl;
}
int getMaximumGenerated(int n) {
    vector<int> generated (n+1,0);
    if(n == 0) return 0;
    generated[0] = 0;
    generated[1] = 1;
    int current = 2;
    int max = 1;
    while(current != n + 1){
        if(current % 2 == 0) generated[current] = generated[current/2];
        else generated[current] = generated[current/2] + generated[current/2 + 1];
        if(generated[current] > max) max = generated[current];
        current++;
    }
    return max;
}
int main() {
    std::cout << getMaximumGenerated(1) << std::endl;
    return 0;
}
