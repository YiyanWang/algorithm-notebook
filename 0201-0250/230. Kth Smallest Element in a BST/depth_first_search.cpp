#include <stack>
using namespace std;

// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    int kthSmallest(TreeNode *root, int k) {
        stack<TreeNode *> dfs;
        TreeNode *current = root;

        while (current != NULL || !dfs.empty()) {
            while (current != NULL) {
                dfs.push(current);
                current = current->left;
            }
            current = dfs.top();
            dfs.pop();

            if (--k == 0) break;

            current = current->right;
        }

        return current->val;
    }
};