#include <math.h>
using namespace std;

// https://leetcode.com/problems/count-complete-tree-nodes/

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
    int countNodes(TreeNode *root) {
        int depth = 0;

        TreeNode *current = root;
        while (current != NULL) {
            depth++;
            current = current->left;
        }
        if (depth <= 1) return depth;

        int count = pow(2, depth - 1) - 1;
        int left = 1, right = count + 1;
        while (left != right) {
            int index = (left + right + 1) / 2;
            int half = (count + 1) / 2;
            current = root;
            while (half > 0) {
                if (index > half) {
                    current = current->right;
                    index -= half;
                } else {
                    current = current->left;
                }
                half /= 2;
            }

            if (current != NULL) left = (left + right + 1) / 2;
            else right = (left + right + 1) / 2 - 1;
        }

        return count + left;
    }
};