#include <vector>
using namespace std;

// https://leetcode.com/problems/gas-station/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = 0;
        int tank = 0;
        bool restart = false;

        int i = 0;
        do {
            if (tank < 0) {
                if (restart) {
                    return -1;
                }
                tank = 0;
                start = i;
            }

            tank += gas[i] - cost[i];
            if (++i == n) {
                i = 0;
                restart = true;
            }
        } while (i != start);

        if (tank >= 0) {
            return start;
        }
        return -1;
    }
};