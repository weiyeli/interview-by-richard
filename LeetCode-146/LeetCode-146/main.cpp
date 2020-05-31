//
//  main.cpp
//  LeetCode-146
//
//  Created by liweiye on 2020/5/31.
//  Copyright © 2020 liweiye. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
private:
    int capacity;
    // 双链表：装着 (key, value) 的元祖
    list<pair<int, int>> cache;
    // 哈希表: key 映射到 (key, value) 在 cache 中的位置
    unordered_map<int, list<pair<int, int>>::iterator> map;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        auto it = map.find(key);
        // 访问的 key 不存在
        if (it == map.end()) return -1;
        // key 存在，把 (key, value) 换到队列头部
        pair<int, int> kv = *map[key];
        cache.erase(map[key]);
        cache.push_front(kv);
        // 更新 (key, value) 在 cache 中的位置
        map[key] = cache.begin();
        return kv.second;
    }

    void put(int key, int value) {
        auto it = map.find(key);
        // 先判断 key 是否已经存在
        if (it == map.end()) {
            // 如果 key 不存在，需要先判断缓存是否已满
            if (cache.size() == capacity) {
                // cache 已满，删除尾部的键值对
                auto lastPair = cache.back();
                int lastKey = lastPair.first;
                map.erase(lastKey);
                cache.pop_back();
            }
            // cache 没满，可以直接添加
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        } else {
            // key 存在，更换 value 并且替换到队列头
            cache.erase(map[key]);
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
