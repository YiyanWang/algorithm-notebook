#include <stack>
using namespace std;

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        stack<TreeNode *> dfs, ancestors;
        dfs.push(root);

        TreeNode *candidate = NULL, *previous, *current;
        while (!dfs.empty()) {
            current = dfs.top();
            if (current->right == previous || current->left == previous) {
                dfs.pop();
                if (ancestors.top() == current) ancestors.pop();
                previous = current;
                continue;
            }

            if (candidate == NULL) {
                ancestors.push(current);
                if (current == p) candidate = q;
                else if (current == q) candidate = p;
            } else if (current == candidate) break;

            if (current->right == NULL && current->left == NULL) {
                dfs.pop();
                if (ancestors.top() == current) ancestors.pop();
            } else {
                if (current->right != NULL) {
                    dfs.push(current->right);
                }
                if (current->left != NULL) {
                    dfs.push(current->left);
                }
            }
            previous = current;
        }

        return ancestors.top();
    }
};