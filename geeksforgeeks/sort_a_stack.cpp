#include <stack>
using namespace std;

// https://www.geeksforgeeks.org/problems/sort-a-stack/1

class SortedStack {
public:
    stack<int> s;
    void sort();
};

void SortedStack::sort() {
    stack<int> tmpStack;
    while (!s.empty()) {
        int num = s.top();
        s.pop();

        while (!tmpStack.empty() && tmpStack.top() > num) {
            s.push(tmpStack.top());
            tmpStack.pop();
        }

        tmpStack.push(num);
    }
    s = tmpStack;
}