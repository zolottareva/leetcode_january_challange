//
//  main.cpp
//  leetcode_january10
//
//  Created by Золотарева Марина Олеговна on 10.01.2021.
//

#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

int insert(vector<int>& nums, int element){
    size_t numsSize = nums.size();
    if(numsSize == 0){
        nums.push_back(element);
        return 0;
    }
    if(nums[numsSize - 1] <= element){
        nums.push_back(element);
        return 0;
    }
    size_t right = numsSize;
    size_t left = 0;
    while (left < right) {
        size_t border = (right + left)/2;
        if (element > nums[border]){
            left = border + 1;
        }
        else
            right = border;
    }
    size_t backCost = right;
    right = numsSize;
    left = 0;
    while (left < right) {
        size_t border = (right + left)/2;
        if (element >= nums[border]){
            left = border + 1;
        }
        else
            right = border;
    }
    size_t frontCost = left;
    nums.insert(nums.begin() + right, element);
    size_t difference = numsSize - frontCost;
    return std::min(backCost, difference);
}
int createSortedArray(vector<int>& instructions) {
    vector <int> nums;
    int cost = 0;
    for(auto element: instructions){
        cost += insert(nums, element);
        cost %= 1000000007;
    }
    return cost;
}
int main() {
    vector <int> vec = {1,2,3,6,5,4};
    std::cout << createSortedArray(vec) << std::endl;
    return 0;
}
