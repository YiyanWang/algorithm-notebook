#include <cstddef>
using namespace std;

// https://leetcode.com/problems/copy-list-with-random-pointer/

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }

        Node* current = head;
        Node* temp;
        while (current != NULL) {
            temp = current->next;
            current->next = new Node(current->val);
            current->next->next = temp;
            current = temp;
        }
        Node* copyHead = head->next;

        current = head;
        while (current != NULL) {
            temp = current->next;
            if (current->random != NULL) {
                temp->random = current->random->next;
            }
            current = temp->next;
        }

        current = head;
        while (current != NULL) {
            temp = current->next;
            current->next = temp->next;

            current = current->next;
            if (current != NULL) {
                temp->next = current->next;
            }
        }

        return copyHead;
    }
};