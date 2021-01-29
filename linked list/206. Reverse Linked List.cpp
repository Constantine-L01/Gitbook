Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL

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
    ListNode* reverseList(ListNode* head) {
    // need a temp because the next node will be lost after cur->next point to previous node.
        ListNode* temp;
        ListNode* cur = head;
        ListNode* pre = NULL;
        
        while(cur) {
            // save next node
            temp = cur->next;
            // change pointer to next node to point to previous node
            cur->next = pre;
            // point pre to cur
            pre = cur;
            // point cur to next node
            cur = temp;
        }
        return pre;
    }
};
