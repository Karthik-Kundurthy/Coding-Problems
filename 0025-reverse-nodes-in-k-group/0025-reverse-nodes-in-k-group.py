# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # end of list or none case
        if (head is None):
            return head
        
        # get the end of the k group
        end = head
        
        # check if enough enough nodes left for k group, move to end of interval
        for i in range(k - 1):
            end = end.next
            if end is None:
                return head
            

        # define next pointer to connect to, will call function on this 
        next_node = end.next
        
        # do reversal iteratively
        prev = None
        curr = head
        # print(curr)
        while curr is not next_node:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
            
        # print(end)
        # print(curr)
        # print(next_node)
        # propogate through LL
        head.next = self.reverseKGroup(next_node, k)
        
        return prev
            
        
        