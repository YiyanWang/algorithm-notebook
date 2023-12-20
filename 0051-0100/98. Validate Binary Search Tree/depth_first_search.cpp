#include <stack>
using namespace std;

// https://leetcode.com/problems/validate-binary-search-tree/

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
    bool isValidBST(TreeNode *root) {
        stack<TreeNode *> dfs;
        TreeNode *current = root;

        int previous;
        bool previousSet = false;
        while (current != NULL || !dfs.empty()) {
            while (current != NULL) {
                dfs.push(current);
                current = current->left;
            }
            current = dfs.top();
            dfs.pop();

            if (previousSet && previous >= current->val) return false;
            previous = current->val;
            previousSet = true;

            current = current->right;
        }

        return true;
    }
};