#include <stack>
using namespace std;

// https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        int num = 0;
        stack<TreeNode *> s;
        if (root != NULL) {
            s.push(root);
        }

        TreeNode *pop = root, *current;
        while (!s.empty()) {
            current = s.top();
            if (current->right == pop || current->left == pop) {
                num /= 10;
                pop = current;
                s.pop();
                continue;
            }

            num = 10 * num + current->val;

            if (current->right == NULL && current->left == NULL) {
                sum += num;
                num /= 10;
                pop = current;
                s.pop();
            } else {
                if (current->right != NULL) {
                    s.push(current->right);
                }
                if (current->left != NULL) {
                    s.push(current->left);
                }
            }
        }

        return sum;
    }
};