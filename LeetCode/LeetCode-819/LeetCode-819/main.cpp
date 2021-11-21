//
//  main.cpp
//  LeetCode-819
//
//  Created by liweiye on 2020/8/19.
//  Copyright © 2020 liweiye. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <sstream>
using namespace std;

string mostCommonWord(string paragraph, vector<string>& banned) {
    unordered_map<string, int> count;
    unordered_set<string> ban;
    for (auto& w: banned) {
        ban.insert(w);
    }
    int maxCount = 0;
    string ans;

    for (auto& c: paragraph) {
        c = isalpha(c) ? c : ' ';
    }
    stringstream ss(paragraph);
    string temp;
    while (ss >> temp) {
        for (auto& c: temp) {
            c = tolower(c);
        }
        if (ban.count(temp) != 0) continue;
        count[temp]++;
        if (count[temp] > maxCount) {
            maxCount = count[temp];
            ans = temp;
        }
    }

    return ans;
}

int main(int argc, const char * argv[]) {
    unordered_set<int> count = {1, 1, 1, 4, 5};
    cout << count.count(1) << endl;
    return 0;
}
