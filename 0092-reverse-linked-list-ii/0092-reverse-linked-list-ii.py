# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        
        k = right - left
        
        dummy = ListNode(0, head)
        prev = dummy
        for i in range(1, left):
            prev = prev.next
        
        # print(prev)
                
        # reverse the next k nodes, known
        def reverse_group(head, k):
            end = head
            for i in range(k):
                end = end.next
            # print(end)
            
            # preserve the connection to this
            next_node = end.next
            # print(next_node)
            
            prev = None
            curr = head
            
            while curr is not next_node:
                nxt = curr.next
                curr.next = prev
                prev = curr
                curr = nxt
            
            
            # maintain a connection in the list
            head.next = next_node
            
            return prev
        
        
        prev.next = reverse_group(prev.next, k)
        
        return dummy.next



