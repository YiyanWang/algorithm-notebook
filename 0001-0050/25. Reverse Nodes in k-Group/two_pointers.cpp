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
        ListNode *current = head;
        int count = 0;
        while (current != NULL && count < k) {
            count++;
            current = current->next;
        }

        if (count == k) {
            current = reverseKGroup(current, k);

            ListNode *temp;
            while (count-- > 0) {
                temp = head->next;
                head->next = current;
                current = head;
                head = temp;
            }
            head = current;
        }

        return head;
    }
};