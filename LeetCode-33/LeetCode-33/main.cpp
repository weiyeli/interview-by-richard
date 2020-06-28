//
//  main.cpp
//  LeetCode-33
//
//  Created by liweiye on 2020/6/28.
//  Copyright © 2020 liweiye. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = (int)nums.size();
        if (size == 0) return -1;
        if (size == 1) return nums[0] == target ? 0 : -1;
        int left = 0, right = size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            // 左边如果是有序数组
            if (nums[left] <= nums[mid]) {
                // 判断在不在左边
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                // 判断在不在右边
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> vec = {4,5,6,7,0,1,2};
    Solution s = Solution();
    cout << s.search(vec, 3) << endl;
}
