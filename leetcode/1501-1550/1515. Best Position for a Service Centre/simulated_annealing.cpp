#include <vector>
#include <iostream>
using namespace std;

// https://leetcode.com/problems/best-position-for-a-service-centre/

class Solution {
private:
    double epsilon = 1e-7;

    double getDistSum(vector<vector<int>> &positions, double x, double y) {
        double sum = 0.0;
        for (vector<int> &position : positions) {
            sum += hypot(x - position[0], y - position[1]);
        }
        return sum;
    }
public:
    double getMinDistSum(vector<vector<int>> &positions) {
        int n = positions.size();
        if (n <= 1) return 0;

        double x = 0.0, y = 0.0;
        double xmax = 0.0, xmin = 100.0, ymax = 0.0, ymin = 100.0;
        for (vector<int> &position : positions) {
            x += position[0];
            y += position[1];
            if (position[0] < xmin) xmin = position[0];
            if (position[0] > xmax) xmax = position[0];
            if (position[1] < ymin) ymin = position[1];
            if (position[1] > ymax) ymax = position[1];
        }
        x /= n;
        y /= n;

        vector<double> directions = { 0.0, 1.0, 0.0, -1.0, 0.0 };

        double oldX, oldY;
        double distSum = getDistSum(positions, x, y), previousDistSum;
        double delta = max(xmax - xmin, ymax - ymin) / 2;
        while (delta > epsilon) {
            oldX = x, oldY = y;
            previousDistSum = distSum;

            for (int i = 0; i < 4; i++) {
                x = oldX + delta * directions[i];
                y = oldY + delta * directions[i + 1];
                distSum = getDistSum(positions, x, y);
                if (distSum < previousDistSum) break;
            }

            if (distSum >= previousDistSum) delta /= 2;
        }

        return distSum;
    }
};

int main() {
    vector<vector<int>> positions;
    positions.push_back({ 0, 1 });
    positions.push_back({ 3, 2 });
    positions.push_back({ 4, 5 });
    positions.push_back({ 7, 6 });
    positions.push_back({ 8, 9 });
    positions.push_back({ 11, 1 });
    positions.push_back({ 2, 12 });
    //32.94036

    Solution solution;
    double ans = solution.getMinDistSum(positions);
    cout << ans << endl;
    return 0;
}