#include <stack>
using namespace std;

// https://leetcode.com/problems/symmetric-tree/

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
    bool isSymmetric(TreeNode *root) {
        stack<TreeNode *> stackLeft, stackRight;
        stackLeft.push(root->left);
        stackRight.push(root->right);

        TreeNode *left, *right;
        while (!stackLeft.empty()) {
            left = stackLeft.top();
            right = stackRight.top();
            stackLeft.pop();
            stackRight.pop();

            if (left == NULL && right == NULL) continue;
            else if (left == NULL || right == NULL) return false;
            else if (left->val != right->val) return false;

            if (left->right != NULL || right->left != NULL) {
                stackLeft.push(left->right);
                stackRight.push(right->left);
            }
            if (left->left != NULL || right->right != NULL) {
                stackLeft.push(left->left);
                stackRight.push(right->right);
            }
        }

        return true;
    }
};