Given an n-ary tree, return the level order traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

Example 1:

Input: root = [1,null,3,2,4,null,5,6]
Output: [[1],[3,2,4],[5,6]]

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> que;
        vector<vector<int>> res;
        
        if(root != nullptr){
            que.push(root);
        }
        
        while(!que.empty()){
            int size = que.size();
            vector<int> vec;
            
            for(int i = 0; i < size; i++) {
                Node* node = que.front();
                que.pop();
                vec.push_back(node->val);
                for(int i = 0; i < node->children.size(); i++){
                    if(node->children[i] != nullptr){
                        que.push(node->children[i]);
                    }
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};
