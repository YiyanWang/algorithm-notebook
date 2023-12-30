using namespace std;

// https://leetcode.com/problems/happy-number/

class Solution {
public:
    bool isHappy(int n) {
        while (n > 0) {
            if (n < 10) {
                if (n == 1 || n == 7) return true;
                else return false;
            }

            int next = 0;
            while (n > 0) {
                int onesPlace = n % 10;
                next += onesPlace * onesPlace;
                n /= 10;
            }
            n = next;
        }

        return false;
    }
};