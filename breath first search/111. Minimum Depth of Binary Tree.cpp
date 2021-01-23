Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 2

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        queue<TreeNode*> Q;
        Q.push(root);
        int node = 0;
        
        while(!Q.empty()) {
            // increment for the root node because the question ask about total nodes
            node++;
            int size = Q.size();
            for (int i = 0; i<size; i++){
                // pop dont return removed element because if exception is thrown in the copy constructor of the element then the element will be lost and also removed from the queue
                TreeNode* curr = Q.front();
                Q.pop();
                if (!curr->left && !curr->right) {
                    return node;
                }
                if (curr->left) {
                    Q.push(curr->left);
                }
                if (curr->right) {
                    Q.push(curr->right);
                }
            }
        }
        return -1;
    }
};
