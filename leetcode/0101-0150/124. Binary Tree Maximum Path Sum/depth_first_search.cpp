#include <__algorithm/max.h>
using namespace std;

// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int maxPathSum(TreeNode *root) {
        int sum = root->val;
        maxPathSum(root, sum);
        return sum;
    }

    int maxPathSum(TreeNode *root, int &sum) {
        if (root == NULL) return 0;

        int left = max(maxPathSum(root->left, sum), 0);
        int right = max(maxPathSum(root->right, sum), 0);
        sum = max(sum, left + right + root->val);
        return max(left, right) + root->val;
    }
};