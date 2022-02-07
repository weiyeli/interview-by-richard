//
//  main.cpp
//  TopKDemo
//
//  Created by Ricardo on 2021/11/21.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 找最大，用小顶堆；找最小，用大顶堆
// 小顶堆是greater，大顶堆是less
// 原理简析: 只要把最小的都剔除出去，那么剩下的就是最大的k个数
// 时间复杂度：O(nlogK)
void findTopK(vector<int> arr, vector<int>& ret, int m) {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < m; i++) {
        q.push(arr[i]);
    }
    int i = m;
    for (; i < arr.size(); i++) {
        if (arr[i] > q.top()) {
            q.pop();
            q.push(arr[i]);
        }
    }
    while (!q.empty()) {
        ret.push_back(q.top());
        q.pop();
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
