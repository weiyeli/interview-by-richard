//
//  main.cpp
//  LeetCode13
//
//  Created by liweiye on 2019/8/29.
//  Copyright © 2019 liweiye. All rights reserved.
//

#include <iostream>
#include <unordered_map>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> T = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    int sum = T[s.back()];
    for (int i = s.length() - 2; i >= 0; --i) {
        if (T[s[i]] < T[s[i+1]]) {
            sum -= T[s[i]];
        } else {
            sum += T[s[i]];
        }
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    string a = "MCMXCIV";
    cout << romanToInt(a) << endl;
}
