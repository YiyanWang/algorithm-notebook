#include <queue>
#include <vector>
using namespace std;

// https://leetcode.com/problems/average-of-levels-in-binary-tree/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> ans;
        queue<TreeNode *> bfs;
        bfs.push(root);

        TreeNode *temp;
        while (!bfs.empty()) {
            int n = bfs.size();
            double sum = 0.0;

            for (int i = 0; i < n; i++) {
                temp = bfs.front();
                bfs.pop();
                sum += temp->val;
                if (temp->left != NULL) bfs.push(temp->left);
                if (temp->right != NULL) bfs.push(temp->right);
            }

            ans.push_back(sum / n);
        }

        return ans;
    }
};