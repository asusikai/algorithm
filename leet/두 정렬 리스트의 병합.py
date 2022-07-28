from typing import List


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:

    global full_list
    full_list = ListNode()

    def mergeTwoLists(self, list1: ListNode, list2: ListNode) -> ListNode:

        

        if (not list1) or (list2 and (list1.val < list2.val)):

            full_list.val = list1.val
            Solution.mergeTwoLists(list1.next, list2)
        
        
            full_list.val = list2.val
            Solution.mergeTwoLists(list1, list2.next)
        
        return full_list
    

    enu
        




        

        
Sol = Solution()

l1 = ListNode(1)
l1.next = ListNode(2)
l1.next.next = ListNode(4)

l2 = ListNode(1)
l2.next = ListNode(3)
l2.next.next = ListNode(4)

def print_val(list: ListNode):
    result = []
    print("Start")
    while(list):
        result.append(list.val)
        list = list.next
            
    print(result)
    print("done")

print_val(l1)
print_val(l2)

#print(Sol.mergeTwoLists(l1, l2).val)