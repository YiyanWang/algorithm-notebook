#include <stack>
#include <vector>
using namespace std;

// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

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
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        TreeNode *head = new TreeNode(preorder[0]);
        stack<TreeNode *> heads;
        heads.push(head);

        int n = preorder.size();
        for (int i = 1; i < n; i++) {
            int val = preorder[i];
            TreeNode *node = new TreeNode(val);

            if (val < heads.top()->val) {
                heads.top()->left = node;
            } else {
                TreeNode *pop;
                while (!heads.empty() && val > heads.top()->val) {
                    pop = heads.top();
                    heads.pop();
                }
                pop->right = node;
            }
            heads.push(node);
        }

        return head;
    }
};