#include <stack>
#include <vector>
using namespace std;

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        int i = 0, j = 0;
        stack<TreeNode *> father;

        TreeNode dummy(INT_MAX);
        TreeNode *current, *root = &dummy;
        father.push(root);

        bool isLeft = false;
        while (i < n) {
            if (inorder[j] == father.top()->val) {
                root = father.top();
                father.pop();
                j++;
                continue;
            }

            current = new TreeNode(preorder[i]);
            if (root->right == NULL) {
                root->right = current;
            } else {
                father.top()->left = current;
            }
            father.push(current);
            i++;
        }

        return dummy.right;
    }
};