#include <queue>
#include <vector>
using namespace std;

// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        queue<TreeNode *> bfs;
        bfs.push(root);

        TreeNode *temp;
        bool toRight = true;
        while (!bfs.empty()) {
            int n = bfs.size();

            vector<int> nums(n, 0);
            for (int i = 0; i < n; i++) {
                temp = bfs.front();
                bfs.pop();
                if (toRight) nums[i] = temp->val;
                else nums[n - i - 1] = temp->val;
                if (temp->left != NULL) bfs.push(temp->left);
                if (temp->right != NULL) bfs.push(temp->right);
            }

            ans.push_back(nums);
            toRight = !toRight;
        }

        return ans;
    }
};