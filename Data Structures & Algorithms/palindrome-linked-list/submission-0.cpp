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
    bool isPalindrome(ListNode* head) {
        // find middle of linked list
        auto* fast = head;
        auto* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // reverse the second half

        ListNode* prev {};
        while (slow != nullptr) {
            ListNode* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        
        // check each number of each half
        ListNode* first = head;
        ListNode* second = prev;

        while (second != nullptr) {
            if (first->val != second->val) {
                return false;
            }
            first = first->next;
            second = second->next;
        }

        return true;
    }
};