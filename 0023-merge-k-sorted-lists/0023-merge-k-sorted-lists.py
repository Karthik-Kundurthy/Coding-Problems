# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        heap = []

        for lis in lists:
            curr = lis
            while curr:
                heap.append(curr.val)
                curr = curr.next

        heapq.heapify(heap)

        print(heap)

        if len(heap) == 0:
            return None


        top = heapq.heappop(heap)
        head = ListNode(top)
        curr = head

        while len(heap) > 0:
            curr.next = ListNode(heapq.heappop(heap))
            curr = curr.next

        return head
        