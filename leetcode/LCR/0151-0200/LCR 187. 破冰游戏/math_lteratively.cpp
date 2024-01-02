#include <iostream>
using namespace std;

// https://leetcode.cn/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/

class Solution {
public:
    int iceBreakingGame(int num, int target) {
        if (target == 1) return num - 1;

        int answer = 0;
        for (int i = 2; i <= num; i++) {
            answer = (target + answer) % i;
        }
        return answer;
    }
};

int main() {
    int n = 7, m = 3;
    int answer = Solution().iceBreakingGame(n, m);
    cout << answer << endl;
    return 0;
}