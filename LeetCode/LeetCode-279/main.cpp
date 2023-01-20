#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int sqrtN = sqrt(n);
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (dp[i] > -1) {
                continue;
            }
            int res = INT_MAX;
            for (int j = 1; j * j <= i; j++) {
                res = min(res, 1 + dp[i-j*j]);
            }
            dp[i] = res;
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    cout << s.numSquares(4) << endl;
}
