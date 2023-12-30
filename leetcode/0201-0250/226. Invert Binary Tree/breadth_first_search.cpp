#include <queue>
using namespace std;

// https://leetcode.com/problems/invert-binary-tree/

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
    TreeNode *invertTree(TreeNode *root) {
        if (root == NULL) return root;

        queue<TreeNode *> q;
        q.push(root);

        TreeNode *node, *temp;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                node = q.front();
                q.pop();
                temp = node->left;
                node->left = node->right;
                node->right = temp;

                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
        }

        return root;
    }
};