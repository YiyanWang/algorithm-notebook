#include <cstddef>
using namespace std;

// https://leetcode.com/problems/reverse-nodes-in-k-group/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        int n = 0;
        for (ListNode *temp = head; temp != NULL; temp = temp->next) {
            n++;
        }

        ListNode dummy = ListNode();
        dummy.next = head;
        ListNode *previous = &dummy, *current = head, *forward;
        ListNode *start = &dummy, *nextStart;
        for (int i = 1; i <= n - n % k; i++) {
            forward = current->next;
            current->next = previous;
            previous = current;
            current = forward;

            if (i % k == 0) {
                nextStart = start->next;
                nextStart->next = current;
                start->next = previous;
                start = nextStart;
            }
        }

        return dummy.next;
    }
};