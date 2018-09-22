# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        numSum = 0;
        str1 = ""
        str2 = ""
        while (l1):
            str1 += str(l1.val)
            l1 = l1.next
        while (l2):
            str2 += str(l2.val)
            l2 = l2.next
            
        strSum = str(int(str1[::-1]) + int(str2[::-1]))
        strSum = strSum[::-1]
        
        listBase = ListNode(0)
        base = listBase
        for c in strSum:
            base.next = ListNode(int(c))
            base = base.next
        return listBase.next