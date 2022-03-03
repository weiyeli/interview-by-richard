//
//  main.cpp
//  offer-03
//
//  Created by ricardooli on 2022/3/3.
//

#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    // 解法1: 使用set
    int findRepeatNumber(vector<int>& nums) {
        set<int> my_set;
        for(int i: nums) {
            if (my_set.count(i)) {
                return i;
            }
            my_set.insert(i);
        }
        return -1;
    }
    
    // 解法2: 原地交换
    int findRepeatNumber2(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == i) {
                i++;
                continue;
            }
            if (nums[nums[i]] == nums[i]) {
                return nums[i];
            }
            swap(nums[i], nums[nums[i]]);
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
