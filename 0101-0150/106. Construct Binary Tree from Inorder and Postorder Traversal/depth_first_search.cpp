#include <stack>
#include <vector>
using namespace std;

// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = inorder.size();
        int i = n - 1, j = n - 1;
        stack<TreeNode *> father;

        TreeNode dummy(INT_MAX);
        TreeNode *current, *root = &dummy;
        father.push(root);

        bool isLeft = false;
        while (j >= 0) {
            if (inorder[i] == father.top()->val) {
                root = father.top();
                father.pop();
                i--;
                continue;
            }

            current = new TreeNode(postorder[j]);
            if (root->left == NULL) {
                root->left = current;
            } else {
                father.top()->right = current;
            }
            father.push(current);
            j--;
        }

        return dummy.left;
    }
};