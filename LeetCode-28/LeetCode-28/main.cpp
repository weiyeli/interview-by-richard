//
//  main.cpp
//  LeetCode-28
//
//  Created by liweiye on 2019/9/27.
//  Copyright © 2019 liweiye. All rights reserved.
//

#include <iostream>
using namespace std;

int strStr(string haystack, string needle) {
    int length1 = haystack.size();
    int length2 = needle.size();

    if (length2 == 0)
        return 0;

    if (length1 == 0 || length2 > length1) return -1;

    int i = 0, j = 0;
    bool flag = false;
    int first = -1;
    while (i < length1 && j < length2) {
        if (haystack[i] == needle[j]) {
            if (!flag) {
                first = i;
                flag = true;
            }
            j++;
            i++;
        } else {
            i = first + 1;
            j = 0;
            flag = false;
            first = -1;
        }
    }
    return first;
}

int main(int argc, const char * argv[]) {
    string haystack = "aaaaa";
    string needle = "bba";
    cout << strStr(haystack, needle) << endl;;
}
