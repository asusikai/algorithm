# Definition for singly-linked list.

class ListNode:
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next

from collections import deque

class Solution:
    def isPalindrome(self, head : ListNode) -> bool:

        if head == None:
            return False

        que =deque()
        current = head
        while(current != None):
            que.append(current.val)
            current = current.next

        
        while que:
            
            if len(que) == 1:
                return True

            if que.pop() == que.popleft():
                continue

            else:
                return False
            
        return True

test = Solution()
head = [1,2]

print(test.isPalindrome(head))