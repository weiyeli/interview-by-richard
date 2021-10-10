//
//  main.cpp
//  LeetCode-179
//
//  Created by liweiye on 2020/4/28.
//  Copyright © 2020 liweiye. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> res;
    string largestNumber(vector<int>& nums) {
        for (auto num: nums) {
            res.push_back(to_string(num));
        }
        sort(res.begin(), res.end(), cmp);
        string s;
        // 考虑为`0`的情况
        if (s[0] == '0') {
            return "0";
        }
        for (string num: res) {
            s.append(num);
        }
        return s;
    }
private:
    bool static cmp(const string& a, const string& b) {
        return a + b > b + a;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> vec = {3, 30, 34, 5, 9};
    string res = s.largestNumber(vec);
    cout << res << endl;
}
