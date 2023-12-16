#include <cstddef>
#include <unordered_map>
using namespace std;

// https://leetcode.com/problems/copy-list-with-random-pointer/

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node *copyRandomList(Node *head) {
        Node *newHead = new Node(0);
        Node *origin = head;
        Node *copy = newHead;

        unordered_map<Node *, Node *> map;
        while (origin) {
            copy->next = new Node(origin->val);
            copy = copy->next;
            map[origin] = copy;
            origin = origin->next;
        }

        origin = head;
        copy = newHead->next;
        while (origin) {
            if (origin->random) {
                copy->random = map[origin->random];
            }
            origin = origin->next;
            copy = copy->next;
        }

        copy = newHead->next;
        delete newHead;
        return copy;
    }
};