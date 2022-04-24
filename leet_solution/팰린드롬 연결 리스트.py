# Definition for singly-linked list.

class ListNode:
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next

from collections import deque

class Solution:
    def isPalindrome(self, head : ListNode) -> bool:

        q : deque = deque()

        if not head:
            return True
        
        node = head

        while node is not None:
            q.append(node.val)
            node = node.next
        
        while len(q) > 1:
            if q.popleft() != q.pop():
                return False
        
        return True
    
    def isPalindrome(self, head : ListNode) -> bool:

        pass