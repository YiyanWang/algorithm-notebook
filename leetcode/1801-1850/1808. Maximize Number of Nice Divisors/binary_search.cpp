using namespace std;

// https://leetcode.com/problems/maximize-number-of-nice-divisors/

class Solution {
public:
    int maxNiceDivisors(int primeFactors) {
        if (primeFactors <= 4) return primeFactors;

        long ans = primeFactors % 3;
        int threeCount = primeFactors / 3;
        if (ans <= 1) {
            ans += 3;
            threeCount -= 1;
        }

        long modulo = 1e9 + 7;
        long remainder = 3;
        while (true) {
            if (threeCount & 1) {
                ans *= remainder;
                ans %= modulo;
            }

            threeCount >>= 1;
            if (threeCount == 0) break;
            remainder *= remainder;
            remainder %= modulo;
        }

        return ans;
    }
};