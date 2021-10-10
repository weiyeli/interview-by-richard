//
//  main.cpp
//  LeetCode-17
//
//  Created by liweiye on 2020/9/1.
//  Copyright © 2020 liweiye. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return combinations;
        string combination;
        backtrack(digits, 0, combination);
        return combinations;
    }

    void backtrack(const string& digits, int index, string& combination) {
        if (index == digits.size()) {
            combinations.push_back(combination);
        } else {
            char digit = digits[index];
            const string& letters = phoneMap.at(digit);
            for (const char& letter: letters) {
                combination.push_back(letter);
                backtrack(digits, index + 1, combination);
                combination.pop_back();
            }
        }
    }
private:
    vector<string> combinations;
    unordered_map<char, string> phoneMap {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
