#include <cstddef>
using namespace std;

// https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
    int sumNumbers(TreeNode *root) {
        return sumNumbers(root, 0);
    }

    int sumNumbers(TreeNode *root, int num) {
        if (root == NULL) {
            return 0;
        }

        num = 10 * num + root->val;
        if (root->right == NULL && root->left == NULL) {
            return num;
        }
        return sumNumbers(root->left, num) + sumNumbers(root->right, num);
    }
};