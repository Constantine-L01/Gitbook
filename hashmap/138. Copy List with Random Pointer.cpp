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
    
    Node* oldHead = head;
    Node* clonedHead = new Node(head->val);
    Node* newHead = clonedHead;
    
    unordered_map<Node*, Node*> map;
    map[oldHead] = newHead;
    
    while(oldHead->next){
        newHead->next = new Node(oldHead->next->val);
        oldHead = oldHead->next;
        newHead = newHead->next;
        map[oldHead] = newHead;
    }
    
    oldHead = head;
    newHead = clonedHead;
    
    while(oldHead){
        newHead->random = oldHead->random ? map[oldHead->random]: NULL;
        oldHead = oldHead->next;
        newHead = newHead->next;
    }
    
    return clonedHead;
    }
};
