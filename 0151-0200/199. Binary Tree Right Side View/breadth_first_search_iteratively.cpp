#include <queue>
#include <vector>
using namespace std;

// https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;
        if (root == NULL) return ans;

        queue<TreeNode *> bfs;
        bfs.push(root);

        while (!bfs.empty()) {
            int n = bfs.size();
            TreeNode *last;

            while (n-- > 0) {
                last = bfs.front();
                bfs.pop();
                if (last->left != NULL) bfs.push(last->left);
                if (last->right != NULL) bfs.push(last->right);
            }

            ans.push_back(last->val);
        }

        return ans;
    }
};