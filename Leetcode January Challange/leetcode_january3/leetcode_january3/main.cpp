//
//  main.cpp
//  leetcode_january3
//
//  Created by Золотарева Марина Олеговна on 03.01.2021.
//

#include <iostream>
#include <vector>

using std::vector;
// vector <int> results = {1, 2, 3, 8, 10, 36, 41, 132, 250, 700, 750, 4010, 4237};
bool checkArrangement(const vector<int>& arrangement){
    for(int index = 1; index <= arrangement.size(); index++){
        if(arrangement[index - 1] % index != 0 && index % arrangement[index - 1] != 0) return false;
    }
    return true;
}
int countArrangement(int n) {
    int counter = 0;
    vector <int> arrangement;
    for(int i = 1; i <= n; i++){
        arrangement.push_back(i);
    }
    do{
        if(checkArrangement(arrangement)) counter++;
    } while ( std::next_permutation(arrangement.begin(), arrangement.end()));
    return counter;
}
int main() {
    std::cout << countArrangement(14) << std::endl;
 //   std::cout << countArrangement(15) << std::endl;
    return 0;
}
