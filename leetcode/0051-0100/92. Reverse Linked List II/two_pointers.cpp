#include <cstddef>
using namespace std;

// https://leetcode.com/problems/reverse-linked-list-ii/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode *reverseHead = head, *beforeReverseHead = NULL;
        int i = 1;
        ListNode *current = head, *next = NULL, *previous = NULL;
        while (current != NULL) {
            next = current->next;

            if (i + 1 == left) {
                beforeReverseHead = current;
                reverseHead = next;
            } else if (i == right + 1) {
                reverseHead->next = current;
                break;
            } else if (i >= left && i <= right) {
                current->next = previous;
                previous = current;
                if (i == right) {
                    if (beforeReverseHead != NULL) {
                        beforeReverseHead->next = current;
                    } else {
                        head = current;
                    }
                }
            }

            current = next;
            i++;
        }

        return head;
    }
};