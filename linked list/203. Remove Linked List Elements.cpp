Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5

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
    
// recursive solution
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) {
            return NULL;
        }
        
        ListNode* result = removeElements(head->next, val);
        
        // if current head value equals to value to be removed then don't link current head to the rest of linked list
        if(head->val == val) {
            return result;
        }
        else {
            head->next = result;
        }
        
        return head;
    }
};

// iterative solution

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy;
        dummy.next = head;
        ListNode* pre = &dummy;
        
        // only need to detect pre->next as scenario of pre -> NULL -> NULL is impossible
        while(!(pre->next == NULL)){
            if(pre->next->val == val){
                pre->next = pre->next->next;
            }
            else {
                pre = pre->next;        
            }
        }
        
        return dummy.next;
    }
};
