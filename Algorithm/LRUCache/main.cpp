#include <iostream>
#include <list>

using namespace std;

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> linkedList;
    unordered_map<int, list<pair<int, int>>::iterator> map;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }
        pair<int, int> kv = *map[key];
        // 删除链表中原来的结点
        linkedList.erase(map[key]);
        // 移动到链表头部
        linkedList.push_front(kv);
        map[key] = linkedList.begin();
        return kv.second;
    }

    void put(int key, int value) {
        // 如果原来不存在
        if (map.find(key) == map.end()) {
            // 如果已经达到了容量上限
            if (linkedList.size() == capacity) {
                // 删掉最后一个
                auto lastPair = linkedList.back();
                int lastKey = lastPair.first;
                map.erase(lastKey);
                linkedList.pop_back();
            }
            // 插入队首
            linkedList.push_front(make_pair(key, value));
            map[key] = linkedList.begin();
        } else {
            // 如果原来就存在，直接移动到队首，然后更新
            linkedList.erase(map[key]);
            linkedList.push_front(make_pair(key, value));
            map[key] = linkedList.begin();
        }
    }
};

int main() {
    LRUCache *cache = new LRUCache(10);
    cache->put(1, 1);
    cache->put(2, 2);
    cache->put(3, 3);
    cache->put(4, 4);
    cache->put(5, 5);

    cout << "value is " << cache->get(1) << endl;
    cout << "value is " << cache->get(2) << endl;
    cout << "value is " << cache->get(3) << endl;
    cout << "value is " << cache->get(4) << endl;
    cout << "value is " << cache->get(5) << endl;
}