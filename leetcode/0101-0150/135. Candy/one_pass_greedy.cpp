#include <vector>
using namespace std;

// https://leetcode.com/problems/candy/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int total = 0;
        int count;
        int min = 1;

        for (int i = 1; i < n + 1; i++) {
            count = 1;
            while (i < n && ratings[i - 1] > ratings[i]) {
                total += count;
                count++;
                i++;
            }

            total += max(min, count);
            if (count > 1) {
                min = 1;
            }

            if (i < n && ratings[i - 1] < ratings[i]) {
                min++;
            } else {
                min = 1;
            }
        }

        return total;
    }
};