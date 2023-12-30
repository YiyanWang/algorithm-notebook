#include <stack>
using namespace std;

// https://leetcode.com/problems/minimum-absolute-difference-in-bst/

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
    int getMinimumDifference(TreeNode *root) {
        stack<TreeNode *> dfs;

        int previous = -1;
        int diff = INT_MAX;
        TreeNode *node = root;
        while (node != NULL || !dfs.empty()) {
            while (node != NULL) {
                dfs.push(node);
                node = node->left;
            }
            node = dfs.top();
            dfs.pop();

            if (previous >= 0)
                diff = min(diff, abs(previous - node->val));
            previous = node->val;

            node = node->right;
        }

        return diff;
    }
};