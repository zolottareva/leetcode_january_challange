//
//  main.cpp
//  leetcode_january6
//
//  Created by Золотарева Марина Олеговна on 06.01.2021.
//

#include <iostream>
#include <vector>

using std::vector;

int findKthPositive(vector<int>& arr, int k) {
    if(arr[0] > k) return k;
    int idealSequence = arr[0];
    int numberOfMissing = arr[0] - 1;
    
    for(auto element: arr){
        while(element != idealSequence){
            numberOfMissing++;
            if(numberOfMissing == k) {
                return idealSequence;
            }
            idealSequence++;
        }
        if(numberOfMissing == k) {
            return idealSequence;
        }
        idealSequence = element + 1;
    }
    return idealSequence - numberOfMissing + k - 1;
}
int main() {
    vector <int> arr = {2,3,4,7,11};
    std:: cout << findKthPositive(arr, 7) << std::endl;
    return 0;
}
