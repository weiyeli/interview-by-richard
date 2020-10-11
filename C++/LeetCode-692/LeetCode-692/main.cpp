//
//  main.cpp
//  LeetCode-692
//
//  Created by liweiye on 2020/8/21.
//  Copyright © 2020 liweiye. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

typedef pair<string, int> P;

struct Greater {
    bool operator()(const P& a, const P& b)const {
        // 先判断频数，再判断字典序
        return (a.second > b.second || (a.second == b.second && a.first < b.first));
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string, int> freq;
        for (auto s: words) freq[s]++;
        Greater greater;
        priority_queue<P, vector<P>, Greater> pq;
        for (auto item: freq) {
            P temp = make_pair(item.first, item.second);
            if (pq.size() < k) pq.push(temp);
            else if (greater(temp, pq.top())) {
                pq.pop();
                pq.push(temp);
            }
        }
        while (k--) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
