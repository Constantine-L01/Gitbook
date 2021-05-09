/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head){
        if(head == NULL){
            return head;
        }    

        Node* l1;
        Node* l2;
        
        // will never execute the case l1 == NULL
        for(l1 = head; l1 != NULL; l1 = l1->next->next){
            l2 = new Node(l1->val);
            l2->next = l1->next;
            l1->next = l2;
        }

        for(l1 = head; l1 != NULL; l1 = l1->next->next){
            if(l1->random != NULL){
                l1->next->random = l1->random->next;
            }
        }
        
        Node* newHead = head->next;
        
        for(l1 = head; l1 != NULL; l1 = l1->next){
            l2 = l1->next;
            l1->next = l1->next->next;
            if(l2->next != NULL){
                l2->next = l2->next->next;
            }
        }

        return newHead;
    }
};
