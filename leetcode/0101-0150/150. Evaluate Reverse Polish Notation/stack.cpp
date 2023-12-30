#include <stack>
#include <string>
using namespace std;

// https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int num = stoi(tokens[0]);
        for (int i = 1; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                num += nums.top();
                nums.pop();
            } else if (tokens[i] == "-") {
                num = nums.top() - num;
                nums.pop();
            } else if (tokens[i] == "*") {
                num *= nums.top();
                nums.pop();
            } else if (tokens[i] == "/") {
                num = nums.top() / num;
                nums.pop();
            } else {
                nums.push(num);
                num = stoi(tokens[i]);
            }
        }
        return num;
    }
};