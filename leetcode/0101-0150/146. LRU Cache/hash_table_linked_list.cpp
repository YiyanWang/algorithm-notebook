#include <list>
#include <unordered_map>
using namespace std;

// https://leetcode.com/problems/lru-cache/

class LRUCache {
public:
    int capacity;
    unordered_map<int, pair<int, list<int>::iterator>> m;
    list<int> l;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()) {
            return -1;
        }

        l.erase(it->second.second);
        l.push_back(key);
        it->second.second = --l.end();
        return it->second.first;
    }

    void put(int key, int value) {
        auto it = m.find(key);
        if (it != m.end()) {
            l.erase(it->second.second);
        } else if (l.size() == capacity) {
            m.erase(l.front());
            l.pop_front();
        }

        l.push_back(key);
        m[key] = { value, --l.end() };
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */