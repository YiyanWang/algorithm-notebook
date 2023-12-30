#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// https://leetcode.com/problems/clone-graph/

class Node {
public:
    int val;
    vector<Node *> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node *cloneGraph(Node *node) {
        if (node == NULL) return node;

        unordered_map<int, Node *> copies;
        queue<Node *> bfs;
        bfs.push(node);
        Node *current;
        while (!bfs.empty()) {
            current = bfs.front();
            bfs.pop();
            Node *copy = new Node(current->val, current->neighbors);
            copies[current->val] = copy;

            for (Node *neighbor : current->neighbors) {
                if (!copies.count(neighbor->val)) {
                    bfs.push(neighbor);
                }
            }
        }

        auto it = copies.begin();
        while (it != copies.end()) {
            Node *copy = it->second;
            for (int i = 0; i < copy->neighbors.size(); i++) {
                int index = copy->neighbors[i]->val;
                copy->neighbors[i] = copies[index];
            }
            it++;
        }

        return copies[1];
    }
};