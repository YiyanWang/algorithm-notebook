#include <iostream>
using namespace std;

// https://leetcode.cn/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/

class Node {
public:
    int val;
    Node *next;

    Node(int val) {
        this->val = val;
    }
};

class Solution {
private:
    Node *buildCircle(int num) {
        Node *head = new Node(1);
        Node *previous = head, *current;
        for (int i = 2; i <= num; i++) {
            current = new Node(i);
            previous->next = current;
            previous = current;
        }
        current->next = head;
        return head;
    }
public:
    int iceBreakingGame(int num, int target) {
        if (target == 1) {
            return num - 1;
        }

        Node *head = buildCircle(num);

        int i = 1;
        Node *previous;
        while (head->next != head) {
            if (i++ % target == 0) {
                previous->next = head->next;
            }
            previous = head;
            head = head->next;
        }

        return head->val - 1;
    }
};

int main() {
    int n = 7, m = 3;
    int answer = Solution().iceBreakingGame(n, m);
    cout << answer << endl;
    return 0;
}