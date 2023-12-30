#include <cstddef>
using namespace std;

// https://leetcode.com/problems/partition-list/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode dummy;
        dummy.next = head;

        ListNode *less = &dummy;
        while (less->next != NULL && less->next->val < x) {
            less = less->next;
        }

        ListNode *greater = less->next;
        ListNode *previous, *temp;
        while (greater != NULL) {
            if (greater->val < x) {
                temp = less->next;
                less->next = greater;
                previous->next = greater->next;
                greater->next = temp;
                less = less->next;
            }
            previous = greater;
            greater = greater->next;
        }

        return dummy.next;
    }
};