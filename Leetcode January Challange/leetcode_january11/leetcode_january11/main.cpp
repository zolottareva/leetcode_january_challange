//
//  main.cpp
//  leetcode_january11
//
//  Created by Золотарева Марина Олеговна on 11.01.2021.
//

#include <iostream>
#include <vector>

using std::vector;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int current = m + n - 1;
    m--;
    n--;
    while(m >= 0 && n >= 0){
        if(nums1[m] > nums2[n]){
            nums1[current] = nums1[m];
            m--;
            current--;
        }
        else{
            nums1[current] = nums2[n];
            n--;
            current--;
        }
    }
    while(n >= 0){
        nums1[current] = nums2[n];
        n--;
        current--;
    }
}
void printVector(const vector<int>& vec){
    for(auto element: vec){
        std::cout << element << " ";
    }
    std::cout << std::endl;
}
int main() {
    vector<int> first = {1};
    vector<int> second = {};
    merge(first, 1, second, 0);
    printVector(first);
    return 0;
}
