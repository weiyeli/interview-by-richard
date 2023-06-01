#include <iostream>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // 反转整个字符串
        reverse(s.begin(), s.end());

        int n = s.size();
        int idx = 0;
        for (int start = 0; start < n; ++start) {
            if (s[start] != ' ') {
                // 填一个空白字符然后将idx移动到下一个单词的开头位置
                if (idx != 0) s[idx++] = ' ';

                // 循环遍历至单词的末尾
                int end = start;
                while (end < n && s[end] != ' ') s[idx++] = s[end++];

                // 反转整个单词
                reverse(s.begin() + idx - (end - start), s.begin() + idx);

                // 更新start，去找下一个单词
                start = end;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }

    string reverseWords2(string s) {
        int n = s.size();
        if (n <= 0) {
            return s;
        }
        // 反转整个字符串
        reverse(s.begin(), s.end());
        // 单词开头
        int start = 0;
        // 单词结尾
        int end = 0;
        // 字符串序号
        int i = 0;
        // 找所有的单词
        for (; start < n; start++) {
            if (s[start] == ' ') {
                continue;
            }
            // 填一个空白字符然后将i移动到下一个单词的开头位置
            if (i != 0) {
                s[i++] = ' ';
            }
            // 找到单词结尾
            end = start;
            while(end < n && s[end] != ' ') {
                // 把这个单词写到字符串前面
                s[i++] = s[end++];
            }

            // 反转整个单词
            reverse(s.begin() + i - (end - start), s.begin() + i);

            // 去找下一个单词
            start = end;
        }
        s.erase(s.begin()+i, s.end());
        return s;
    }
};

int main() {
    Solution solution;
    string s = "  hello world!  ";
    string ans = solution.reverseWords2(s);
    cout << ans << endl;
}
