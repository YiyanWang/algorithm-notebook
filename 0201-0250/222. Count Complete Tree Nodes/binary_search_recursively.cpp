#include <cstddef>
using namespace std;

// https://leetcode.com/problems/count-complete-tree-nodes/

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
    int countNodes(TreeNode *root) {
        int leftDepth = countLeftDepth(root);
        if (leftDepth <= 1) return leftDepth;
        return countNodes(root, leftDepth);
    }

    int countNodes(TreeNode *root, int depth) {
        if (depth == 1) return 1;
        int leftDepth = countLeftDepth(root->right);
        TreeNode *next = leftDepth == --depth ? root->right : root->left;
        return (1 << leftDepth) + countNodes(next, depth);
    }

    int countLeftDepth(TreeNode *root) {
        int depth = 0;
        while (root != NULL) {
            depth++;
            root = root->left;
        }
        return depth;
    }
};