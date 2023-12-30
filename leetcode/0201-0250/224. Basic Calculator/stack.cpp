#include <stack>
#include <string>
using namespace std;

// https://leetcode.com/problems/basic-calculator/

class Solution {
public:
    int calculate(string s) {
        s = '(' + s + ')';

        stack<int> nums;
        stack<int> signs;
        int num = 0;
        int sign = 1;
        int start;
        int length = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                if (length++ == 0) {
                    start = i;
                }
            } else if (s[i] != ' ') {
                if (length > 0) {
                    num += sign * stoi(s.substr(start, length));
                    length = 0;
                }

                if (s[i] == '(') {
                    nums.push(num);
                    signs.push(sign);
                    num = 0;
                    sign = 1;
                } else if (s[i] == ')') {
                    sign = signs.top();
                    num = nums.top() + sign * num;
                    signs.pop();
                    nums.pop();
                } else if (s[i] == '+') {
                    sign = 1;
                } else if (s[i] == '-') {
                    sign = -1;
                }
            }
        }

        return num;
    }
};