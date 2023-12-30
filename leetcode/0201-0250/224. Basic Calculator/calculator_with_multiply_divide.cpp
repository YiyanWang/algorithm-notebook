#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    int calculate(string str) {
        stack<int> nums;
        stack<char> signs;
        string numStr = "";

        int n = str.size();
        for (int i = 0; i < n; i++) {
            char c = str[i];
            if (c >= '0' && c <= '9') {
                numStr += c;
            } else {
                int num = stoi(numStr);
                numStr = "";

                nums.push(num);
                signs.push(c);
            }
        };

        int ans = 0, right = stoi(numStr);
        while (!signs.empty()) {
            char sign = signs.top();
            signs.pop();
            int left = nums.top();
            nums.pop();

            if (sign == '+') {
                ans += right;
                right = left;
            } else if (sign == '-') {
                ans -= right;
                right = left;
            } else if (sign == '*') {
                right *= left;
            } else if (sign == '/') {
                right = left / right;
            }
        }
        return ans + right;
    }
};

int main() {
    string str = "11*2+3*4";
    Solution solution;
    int ans = solution.calculate(str);
    cout << ans << endl;
    return 0;
}