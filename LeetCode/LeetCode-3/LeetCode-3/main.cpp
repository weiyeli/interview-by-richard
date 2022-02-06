//
//  main.cpp
//  LeetCode-3
//
//  Created by ricardooli on 2022/2/6.
//

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

// 答案：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-by-leetc-2/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = (int)s.size();
        unordered_set<char> my_set;
        int r = -1;
        int ans = 0;
        for (int i = 0; i < length; i++) {
            if (i != 0) {
                my_set.erase(s[i-1]);
            }
            while ((r+1) < length && my_set.count(s[r+1]) == 0) {
                my_set.insert(s[++r]);
            }
            ans = max(ans, r - i + 1);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    string test1 = "abcabcbb";
    string test2 = "";
    string test3 = "a";
    
    Solution s;
    cout << "ans1: " << s.lengthOfLongestSubstring(test1) << endl;
    cout << "ans2: " << s.lengthOfLongestSubstring(test2) << endl;
    cout << "ans3: " << s.lengthOfLongestSubstring(test3) << endl;
    
    return 0;
}
