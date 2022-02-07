//
//  main.cpp
//  LRUCache
//
//  Created by ricardooli on 2022/2/6.
//

#include <iostream>
#include <list>
#include <utility>
#include <unordered_map>

using namespace std;

//使用hash_map和list实现的LRU。 实现了get和put操作
//get: 得到对应的value，并且移到队列首。
//put: 不存在：队列首加入，此时根据容量可能会挤掉尾元素。存在：移动到队列首。


// 改进点: 如果get发生缺页是否需要处理，这时候可以添加一个
// hash_map存储key-value，并在get不到数据时，put一下即可。
// 参考资料: https://zhuanlan.zhihu.com/p/34133067

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

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
