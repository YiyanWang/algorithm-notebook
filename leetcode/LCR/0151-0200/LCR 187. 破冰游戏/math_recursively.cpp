#include <iostream>
using namespace std;

// https://leetcode.cn/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/

class Solution {
public:
    int iceBreakingGame(int num, int target) {
        if (target == 1) return num - 1;
        if (num == 1) return 0;

        int step = iceBreakingGame(num - 1, target);
        return (target + step) % num;
    }
};

int main() {
    int n = 7, m = 3;
    int answer = Solution().iceBreakingGame(n, m);
    cout << answer << endl;
    return 0;
}