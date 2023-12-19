#include <cstddef>
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
        if (root == NULL || root == q || root == p) return root;
        TreeNode *left = lowestCommonAncestor(root->left, q, p);
        TreeNode *right = lowestCommonAncestor(root->right, q, p);
        if (right != NULL && left != NULL) return root;
        return right != NULL ? right : left;
    }
};