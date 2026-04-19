# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if not list1 and not list2:
            return None
        if not list1:
            return list2
        if not list2:
            return list1
        
        if list1.val > list2.val:
            list1, list2 = list2, list1

        curr1 = list1
        prev1 = None
        curr2 = list2
        
        while curr1 and curr2:
            if curr2.val <= curr1.val:
                next_node2 = curr2.next
                if prev1:
                    prev1.next = curr2
                else:
                    list1 = curr2
                
                curr2.next = curr1
                prev1 = curr2
                curr2 = next_node2
            else:
                prev1 = curr1
                curr1 = curr1.next
        if curr2:
            prev1.next = curr2

        return list1
            