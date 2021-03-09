Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

Example 1:

Input: root = [1,null,3,2,4,null,5,6]
Output: 3
  
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

// recursive solution
class Solution {
public:
    int maxDepth(Node* root) {
        if(root == nullptr){
            return 0;
        }
        int depth = 0;
        for(int i = 0; i < root->children.size(); i++){
            depth = max(depth, maxDepth(root->children[i]));
        }
        return depth + 1;
    }
};
