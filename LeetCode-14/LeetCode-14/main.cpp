//
//  main.cpp
//  LeetCode-14
//
//  Created by liweiye on 2020/5/27.
//  Copyright © 2020 liweiye. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) return "";
            }
        }
        return prefix;
    }
};

int main(int argc, const char * argv[]) {
    vector<string> v = {"abc", "abcdef", "ab", "ab123", "abshjdshak"};
    Solution s;
    cout << s.longestCommonPrefix(v) << endl;
    return 0;
}
