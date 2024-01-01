#include <vector>
#include <iostream>
using namespace std;

// https://leetcode.com/problems/best-position-for-a-service-centre/

class Solution {
private:
    double epsilon = 5e-7;

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
        for (vector<int> &position : positions) {
            x += position[0];
            y += position[1];
        }
        x /= n;
        y /= n;

        double distSum = getDistSum(positions, x, y), previousDistSum;
        do {
            previousDistSum = distSum;

            vector<double> numerator = { 0.0, 0.0 };
            double denominator = 0.0;
            for (vector<int> &position : positions) {
                double dist = hypot(x - position[0], y - position[1]);
                if (dist > 0) {
                    numerator[0] += position[0] / dist;
                    numerator[1] += position[1] / dist;
                    denominator += 1 / dist;
                }
            }
            if (denominator > 0.0) {
                x = numerator[0] / denominator;
                y = numerator[1] / denominator;
            }

            distSum = getDistSum(positions, x, y);
        } while (previousDistSum - distSum > epsilon);

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