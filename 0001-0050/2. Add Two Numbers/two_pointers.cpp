using namespace std;

// https://leetcode.com/problems/add-two-numbers/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;

        ListNode* head = new ListNode();
        ListNode* next = head;
        while (l1 || l2 || sum) {
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            next->next = new ListNode(sum % 10);
            next = next->next;
            sum /= 10;
        }

        next = head->next;
        delete head;
        return next;
    }
};