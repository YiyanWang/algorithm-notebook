#include <queue>
using namespace std;

// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node *connect(Node *root) {
        queue<Node *> q;
        if (root != NULL) {
            q.push(root);
        }

        Node *previous;
        while (!q.empty()) {
            int i = q.size();
            previous = NULL;

            while (i-- > 0) {
                if (previous != NULL) {
                    previous->next = q.front();
                }
                previous = q.front();
                q.pop();
                if (previous->left != NULL) {
                    q.push(previous->left);
                }
                if (previous->right != NULL) {
                    q.push(previous->right);
                }
            }
        }

        return root;
    }
};