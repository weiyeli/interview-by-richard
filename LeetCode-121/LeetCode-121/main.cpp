//
//  main.cpp
//  LeetCode-121
//
//  Created by liweiye on 2020/5/2.
//  Copyright © 2020 liweiye. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i] 表示前i天的最大利润，因为我们始终要使利润最大化，则dp公式为: `dp[i] = max(dp[i-1], prices[i] - minprice)`
        int n = (int)prices.size();
        if (n == 0) return 0;
        int minPrice = 1e9;
        vector<int> dp (n, 0);
        for (int i = 1; i < n; i++) {
            minPrice = min(minPrice, prices[i]);
            dp[i] = max(dp[i-1], prices[i] - minPrice);
        }
        return dp[n-1];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> vec = {7,1,5,3,6,4};
    int res = s.maxProfit(vec);
    cout << res << endl;
}
