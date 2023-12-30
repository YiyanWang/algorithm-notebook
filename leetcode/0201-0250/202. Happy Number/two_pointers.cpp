using namespace std;

// https://leetcode.com/problems/happy-number/

class Solution {
public:
    bool isHappy(int n) {
        int fast = n, slow = n;
        do {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(fast);
            fast = digitSquareSum(fast);
        } while (slow != fast);
        return slow == 1;
    }

    int digitSquareSum(int n) {
        int sum = 0, onesPlace;
        while (n) {
            onesPlace = n % 10;
            sum += onesPlace * onesPlace;
            n /= 10;
        }
        return sum;
    }
};