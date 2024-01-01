#include <vector>
#include <iostream>
using namespace std;

// https://leetcode.com/problems/best-position-for-a-service-centre/

class Solution {
private:
    double epsilon = 1e-7;

    double getDistSum(vector<vector<int>> &positions, double x, double y, bool swapAxes) {
        double sum = 0.0, squareSum;
        for (vector<int> &position : positions) {
            squareSum = pow(x - position[swapAxes], 2);
            squareSum += pow(y - position[!swapAxes], 2);
            sum += sqrt(squareSum);
        }
        return sum;
    }

    double ternarySearch(vector<vector<int>> &positions, double l, double r, bool swapAxes, double y) {
        double mid0, mid1, sum0, sum1;
        while (r - l > epsilon) {
            mid0 = (l + r) / 2;
            mid1 = (mid0 + r) / 2;
            sum0 = getDistSum(positions, mid0, y, swapAxes);
            sum1 = getDistSum(positions, mid1, y, swapAxes);
            if (sum0 - sum1 > epsilon) l = mid0;
            else r = mid1;
        }
        return l;
    }
public:
    double getMinDistSum(vector<vector<int>> &positions) {
        double xmax = 0.0, xmin = 100.0, ymax = 0.0, ymin = 100.0;
        for (vector<int> position : positions) {
            if (position[0] < xmin) xmin = position[0];
            if (position[0] > xmax) xmax = position[0];
            if (position[1] < ymin) ymin = position[1];
            if (position[1] > ymax) ymax = position[1];
        }

        double x = xmin, y = ymin;
        double oldX, oldY;
        do {
            oldX = x, oldY = y;
            x = ternarySearch(positions, xmin, xmax, false, y);
            y = ternarySearch(positions, ymin, ymax, true, x);
        } while (abs(oldX - x) > epsilon || abs(oldY - y) > epsilon);

        return getDistSum(positions, x, y, false);
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