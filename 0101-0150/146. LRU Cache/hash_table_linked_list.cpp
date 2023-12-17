#include <list>
#include <unordered_map>
using namespace std;

// https://leetcode.com/problems/lru-cache/

class LRUCache {
public:
    int capacity;
    unordered_map<int, pair<int, list<int>::iterator>> map;
    list<int> l;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (map.count(key)) {
            updateHistory(key);
            return map[key].first;
        }
        return -1;
    }

    void put(int key, int value) {
        if (map.count(key)) {
            map[key].first = value;
            updateHistory(key);
            return;
        }

        if (map.size() == capacity) {
            map.erase(l.front());
            l.pop_front();
        }
        l.push_back(key);
        map[key] = { value, --l.end() };
    }
private:
    void updateHistory(int key) {
        l.erase(map[key].second);
        l.push_back(key);
        map[key].second = --l.end();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */