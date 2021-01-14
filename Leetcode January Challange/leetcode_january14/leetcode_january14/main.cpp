//
//  main.cpp
//  leetcode_january14
//
//  Created by Золотарева Марина Олеговна on 14.01.2021.
//

#include <iostream>
#include <vector>

using std::vector;

int minOperations(vector<int>& nums, int x) {
    int totalSum = 0;
    for (auto element: nums){
        totalSum += element;
    }
    if (totalSum < x) return -1;
    if (totalSum == x) return nums.size();
    
    size_t numsSize = nums.size();
    int target = totalSum - x;
    int maxlen = -1;
    int i = 0,j = 0;
    int current = 0;
    while(j < numsSize)
    {
        current += nums[j];
        while(current > target)
        {
            current -= nums[i];
            i++;
        }
        if(current == target) maxlen = std::max(maxlen, j - i + 1);
        j++;
    }
    if(maxlen == -1) return -1;
    return numsSize - maxlen;
}
int main() {
    
    return 0;
}
