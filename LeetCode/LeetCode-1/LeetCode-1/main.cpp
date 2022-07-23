//
//  main.cpp
//  LeetCode-1
//
//  Created by ricardooli on 2022/7/18.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashTable;
        for (int i = 0; i < nums.size(); i++) {
            auto it = hashTable.find(target - nums[i]);
            if (it != hashTable.end()) {
                return {it->second, i};
            }
            hashTable[nums[i]] = i;
        }
        return {};
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> test1 = {3,2,4};
    vector<int> res1 = s.twoSum(test1, 6);
    cout << res1[0] << res1[1] << endl;
}
