#include <unordered_map>
using namespace std;

// https://leetcode.com/problems/insert-delete-getrandom-o1/

class RandomizedSet {
private:
    unordered_map<int, int> val_order;
    unordered_map<int, int> order_val;
public:
    RandomizedSet() {

    }

    bool insert(int val) {
        if (val_order.contains(val)) {
            return false;
        }

        int order = val_order.size();
        val_order.insert({ val, order });
        order_val.insert({ order, val });
        return true;
    }

    bool remove(int val) {
        auto search = val_order.find(val);
        if (search == val_order.end()) {
            return false;
        }

        int order = search->second;
        int last = order_val.size() - 1;
        int last_value = order_val[last];
        order_val[order] = last_value;
        val_order[last_value] = order;
        val_order.erase(val);
        order_val.erase(last);
        return true;
    }

    int getRandom() {
        int num = rand() % order_val.size();
        return order_val[num];
    }
};