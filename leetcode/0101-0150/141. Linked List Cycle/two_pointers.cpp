#include <cstddef>
using namespace std;

// https://leetcode.com/problems/linked-list-cycle/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head;
        do {
            slow = slow->next;
            fast = fast->next;
            if (!fast || !fast->next) {
                return false;
            }
            fast = fast->next;
        } while (slow != fast);
        return true;
    }
};