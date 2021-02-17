class MyLinkedList {
public:
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val): val(val), next(nullptr) {};
    };
    
    /** Initialize your data structure here. */
    MyLinkedList() {
        _dummyNode = new LinkedNode(0);
        _size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= _size || index < 0) {
            return -1;
        }
        
        LinkedNode* cur = _dummyNode->next;
        // Due to cur = _dummyNode->next, cur will arrive at the index-th element. 
        while(index--) {
            cur = cur->next;
        }        
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = _dummyNode->next;
        _dummyNode->next = newNode;
        _size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyNode;
        while(cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > _size) {
            return;
        }
        LinkedNode* newNode = new LinkedNode(val);                     
        LinkedNode* cur = _dummyNode;
        // cur = _dummyNode, thus cur will reach the node before index-th
        while(index--) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= _size || index < 0) {
            return;
        }
        LinkedNode* cur = _dummyNode;
        while(index--) {
            cur = cur->next;
        }
        LinkedNode* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        _size--;
    }
    private:
    int _size;
    LinkedNode* _dummyNode;
};
