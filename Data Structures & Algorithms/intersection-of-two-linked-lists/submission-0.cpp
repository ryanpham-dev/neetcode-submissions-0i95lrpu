/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    auto *node1 {headA};
    auto *node2 {headB};
    while (node1 != node2) {
        if (node1) {
            node1 = node1->next;
        } else {
            node1 = headB;
        }

        if (node2) {
            node2 = node2->next;
        } else {
            node2 = headA;
        }
    }
    return node1;
  }
};