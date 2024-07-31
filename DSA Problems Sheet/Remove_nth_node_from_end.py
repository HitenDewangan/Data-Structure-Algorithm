'''
19. Remove Nth Node From End of List

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]
'''

#==========================================================================================================
from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:

        root = ListNode(0)
        root.next = head

        #calculating size of list
        size = 0
        trav = head
        while(trav != None):
            trav = trav.next
            size += 1

        #delete node
        node = root.next
        prev = root
        index_to_search = size - n   # index of the node to keep (previous to target)
        i = 0
        while (i < index_to_search):
            prev = node
            node = node.next
            i += 1 
        
        prev.next = node.next

        return root.next

#==========================================================================================================
l = Solution()
print(l)
print(l.removeNthFromEnd([1,2,3,4,5], 2))
# print(l)



'''
#calculating size of list
        size = 0
        trav = head
        while(trav != None):
            trav = trav.next
            size += 1

        # if nth node is head of the list, deleting first node
        if n==size:        
            prev = head
            head = head.next
            del prev
            return head.next
        
        #delete node
        node = head
        prev = None
        index_to_search = size - n   #index_to_search for storing previous node address
        
        i = 0
        while (i < index_to_search):
            prev = node
            node = node.next
            i += 1 
        
        prev.next = node.next
        del node
        return root.next
'''