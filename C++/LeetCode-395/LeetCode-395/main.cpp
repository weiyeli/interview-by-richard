//
//  main.cpp
//  LeetCode-395
//
//  Created by liweiye on 2020/9/15.
//  Copyright © 2020 liweiye. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char, int> umap;
        for (char c: s) umap[c]++;
        vector<int> split;
        for (int i = 0; i < s.size(); i++) {
            if (umap[s[i]] < k) split.push_back(i);
        }
        if (split.size() == 0) return (int)s.length();
        int ans = 0, left = 0;
        split.push_back((int)s.length());
        for (int i = 0; i < split.size(); i++) {
            // 这里长度不加一是因为不包括split本身
            int len = split[i] - left;
            if (len > ans) ans = max(ans, longestSubstring(s.substr(left, len), k));
            left = split[i] + 1;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    cout << s.longestSubstring("aaabb", 3) << endl;
    string s1 = "abc";
    while (next_permutation(s1.begin(), s1.end())) cout << s1 << endl;;
}
