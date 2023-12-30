#include <cstddef>
using namespace std;

// https://leetcode.com/problems/rotate-list/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL) return head;

        ListNode *fast = head, *slow = head;
        int i = 1;
        while (fast->next != NULL) {
            fast = fast->next;
            if (i > k) {
                slow = slow->next;
            }
            i++;
        }

        if (i <= k) {
            k = k % i;
            if (k == 0) return head;
            else return rotateRight(head, k);
        }

        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        return head;
    }
};