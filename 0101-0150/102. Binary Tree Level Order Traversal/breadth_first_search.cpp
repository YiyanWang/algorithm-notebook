#include <queue>
#include <vector>
using namespace std;

// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        queue<TreeNode *> bfs;
        bfs.push(root);

        TreeNode *temp;
        while (!bfs.empty()) {
            int n = bfs.size();

            vector<int> nums;
            while (n-- > 0) {
                temp = bfs.front();
                bfs.pop();
                nums.push_back(temp->val);
                if (temp->left != NULL) bfs.push(temp->left);
                if (temp->right != NULL) bfs.push(temp->right);
            }

            ans.push_back(nums);
        }

        return ans;
    }
};