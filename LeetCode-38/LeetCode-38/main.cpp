//
//  main.cpp
//  LeetCode-38
//
//  Created by liweiye on 2019/9/15.
//  Copyright © 2019 liweiye. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

string countAndSay(int n) {
    string newResult = "";
    if (n == 1) {
        return "1";
    } else if (n == 2) {
        return "11";
    } else {
        string lastResult = countAndSay(n - 1);
        int count = 1;
        for (int i = 1; i < lastResult.size(); i++) {
            if (lastResult[i] != lastResult[i-1]) {
                newResult += '0' + count;
                newResult += lastResult[i-1];
                count = 1;
            } else {
                count++;
            }
            if (i == lastResult.size() - 1) {
                newResult += '0' + count;
                newResult += lastResult[i];
            }
        }
    }
    return newResult;
}

int main(int argc, const char * argv[]) {
    cout << countAndSay(5) << endl;
}
