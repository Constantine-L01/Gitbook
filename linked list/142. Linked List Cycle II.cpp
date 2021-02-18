Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Notice that you should not modify the linked list.

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// the fast pointer will pass through y 2 times, x 1 times, z 1 times, thus x = z to uphold the fact that fast pointer with 2x speed will travel twice distances than slow pointer
// slow pointer will only travel through y 1 times, x 1 times, thus 2(x + y) = 2y + x + z and x = z
// if z is shorter than x, then 2(x + y) = x + n(y + z) + y, then 2x = x + n(y + z) - y, then x = n(y + z) - y, then x = (n - 1)(y + z) + z 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) {
                ListNode* index1 = head;
                ListNode* index2 = fast;
                
                while(index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                
                return index1;
            }
        }
        return NULL;
    }
};
