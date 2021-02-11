Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL

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
    ListNode* successor = NULL;
    ListNode* reverseFirstN(ListNode* head, int n) {
        if(n == 1) {
            successor = head->next;
            return head;
        }
        
        // last always will be the same which is the head return from the n == 1
        // first round will be n e.g. 3 then 2 
        ListNode* last = reverseFirstN(head->next, n-1);
        head->next->next = head;
        // point the first element in the original linked list to the element after the last element
        head->next = successor;
        
        return last;
    }
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == 1) {
        // e.g. reverse 3 element n = 3
            return reverseFirstN(head, n);
        }
        
        head->next = reverseBetween(head->next, m-1, n-1);
        
        return head;
    }
};
