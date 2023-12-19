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
        stack<TreeNode *> s;
        if (root != NULL) {
            s.push(root);
        }

        TreeNode *child = NULL, *temp;
        while (!s.empty()) {
            if (s.top()->right != NULL) {
                temp = s.top()->right;
                s.top()->right = NULL;
                s.push(temp);
            } else if (s.top()->left != NULL) {
                temp = s.top()->left;
                s.top()->left = NULL;
                s.push(temp);
            } else {
                if (child != NULL) {
                    s.top()->right = child;
                }
                child = s.top();
                s.pop();
            }
        }
    }
};