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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // Increase lag so a stops right behind node to remove
        ListNode* dummy = new ListNode(0, head);
        
        // lagging
        ListNode* a = dummy;
        
        // leading
        ListNode* b = head;
        
        
        // initialize b
        for (int i = 0; i < n; i++) {
            b = b -> next;
        }
        
        // move simultaneously until a right behind node to remove
        while (b) {
            a = a -> next;
            b = b -> next;
        }
        
        a -> next = a -> next -> next;
        
        return dummy -> next;
        
    }
};