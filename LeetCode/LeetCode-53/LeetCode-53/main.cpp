//
//  main.cpp
//  LeetCode-53
//
//  Created by liweiye on 2020/5/3.
//  Copyright © 2020 liweiye. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = (int)nums.size();
        if (size <= 0) return 0;
        vector<int> dp(size, -1e9);
        dp[0] = nums[0];
        int ans = nums[0];
        for (int i = 1; i < size; i++) {
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            ans = max(dp[i], ans);
        }

        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> vec = {-2,1,-3,4,-1,2,1,-5,4};
    int res = s.maxSubArray(vec);
    cout << res << endl;
}
