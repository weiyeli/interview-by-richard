//
//  main.cpp
//  LeetCode-279
//
//  Created by Ricardo on 2021/11/20.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 方法1: 动态规划
    // 状态转移方程：f(i) = 1 + f(i - j * j)
    int numSquares(int n) {
        vector<int> f(n+1);
        for (int i = 1; i <= n; i++) {
            int minn = INT_MAX;
            for (int j = 1; j * j <= i; j++) {
                minn = min(minn, 1 + f[i - j * j]);
            }
            f[i] = minn;
        }
        return f[n];
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.numSquares(12) << endl;
}
