#include <stack>
using namespace std;

// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
    void flatten(TreeNode *root) {
        if (root == nullptr) return;
        stack<TreeNode *> s;
        TreeNode dummy;
        TreeNode *head = &dummy;

        s.push(root);
        while (!s.empty()) {
            TreeNode *current = s.top();
            s.pop();

            head->right = current;
            head = current;

            if (current->right != nullptr) {
                s.push(current->right);
                current->right = nullptr;
            }
            if (current->left != nullptr) {
                s.push(current->left);
                current->left = nullptr;
            }
        }
    }
};