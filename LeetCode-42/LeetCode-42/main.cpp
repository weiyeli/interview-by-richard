//
//  main.cpp
//  LeetCode-42
//
//  Created by liweiye on 2020/5/2.
//  Copyright © 2020 liweiye. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        int ans = 0;
        int size = (int)height.size();
        vector<int> left_max(size), right_max(size);
        left_max[0] = height[0];
        right_max[size-1] = height[size-1];
        for (int i = 1; i < size; i++) {
            left_max[i] = max(height[i], left_max[i - 1]);
        }
        for (int i = size - 2; i >= 0; i--) {
            right_max[i] = max(height[i], right_max[i+1]);
        }
        for (int i = 1; i < size; i++) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }

        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    vector<int> vec;
    int res = solution.trap(vec);
    cout << res << endl;
}
