#include <stack>
#include <string>
using namespace std;

// https://leetcode.com/problems/min-stack/

class MinStack {
public:
    stack<int> numStack;
    stack<int> minStack;

    MinStack() {

    }

    void push(int val) {
        numStack.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if (numStack.top() == minStack.top()) {
            minStack.pop();
        }
        numStack.pop();
    }

    int top() {
        return numStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */