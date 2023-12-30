#include <cstddef>
using namespace std;

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *current = head, *forward = head;
        while (n-- > 0) {
            forward = forward->next;
        }

        if (forward == NULL) {
            return head->next;
        }

        while (forward->next != NULL) {
            current = current->next;
            forward = forward->next;
        }
        current->next = current->next->next;
        return head;
    }
};