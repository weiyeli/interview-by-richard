//
//  main.cpp
//  LeetCode-20
//
//  Created by liweiye on 2019/9/14.
//  Copyright © 2019 liweiye. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

bool isValid(string s) {

    unordered_map<char, char> map;
    stack<char> s1;

    map['['] = ']';
    map['{'] = '}';
    map['('] = ')';

    for (auto& item: s) {
        if (item == '[' || item == '{' || item == '(') {
            s1.push(item);
        } else if (item == ']' || item == '}' || item == ')') {
            char s = '0';
            if (!s1.empty()) {
                s = s1.top();
            } else {
                return false;
            }
            if (map[s] != item) {
                return false;
            } else {
                if (!s1.empty()) {
                    s1.pop();
                }
            }
        } else {
            return false;
        }
    }
    if (s1.empty()) {
        return true;
    } else {
        return false;
    }
}

int main(int argc, const char * argv[]) {
    string test = "[";
    cout << isValid(test) << endl;
}
