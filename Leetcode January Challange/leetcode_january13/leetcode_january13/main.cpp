//
//  main.cpp
//  leetcode_january13
//
//  Created by Золотарева Марина Олеговна on 13.01.2021.
//

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

int numRescueBoats(vector<int>& people, int limit) {
    int numberOfBoats = 0;
    std::sort(people.begin(), people.end());
    size_t indexFront = 0;
    size_t peopleSize = people.size();
    size_t indexBack = peopleSize - 1;
    size_t numberOfPeople = 0;
    if (indexFront == indexBack) return 1;
    while(numberOfPeople < peopleSize){
        if(people[indexBack] + people[indexFront] <= limit){
            indexFront++;
            indexBack--;
            numberOfPeople+=2;
        }
        else {
            indexBack--;
            numberOfPeople++;
        }
        numberOfBoats++;
    }
    return numberOfBoats;
}
int main() {
    vector <int> people = {1,2,2,3,4};
    int limit = 4;
    std::cout << numRescueBoats(people, limit) << std::endl;
    return 0;
}
