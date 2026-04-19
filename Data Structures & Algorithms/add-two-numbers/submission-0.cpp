/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode dummyNode{ListNode(0)};
    ListNode *current{&dummyNode};
    int carry{};
    while (((l1 != nullptr) && (l2 != nullptr)) || (l1 != nullptr) ||
           (l2 != nullptr)) {
      int sumDigit{((l1 != nullptr) ? (l1->val) : 0) +
                   ((l2 != nullptr) ? (l2->val) : 0) + carry};
      if (sumDigit >= 10) {
        carry = sumDigit / 10;
        sumDigit = sumDigit % 10;
      } else {
        carry = 0;
      }
      ListNode *digitNode{new ListNode(sumDigit)};
      current->next = digitNode;
      current = current->next;
      if (l1 != nullptr) {
        l1 = l1->next;
      }
      if (l2 != nullptr) {
        l2 = l2->next;
      }
    }

    if (carry != 0) {
      ListNode *digitNode{new ListNode(carry)};
      current->next = digitNode;
    }

    return dummyNode.next;
  }
};