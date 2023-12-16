#include <cstddef>
using namespace std;

// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return NULL;

        ListNode dummy;
        dummy.next = head;
        ListNode *previous = &dummy, *current = head->next;
        while (current != NULL) {
            if (current->val != previous->next->val) {
                if (current == previous->next->next) {
                    previous = previous->next;
                } else {
                    previous->next = current;
                }
            }
            current = current->next;
        }
        if (previous->next->next != current) {
            previous->next = current;
        }

        return dummy.next;
    }
};