Given the root of a binary tree, flatten the tree into a "linked list":

    The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
    The "linked list" should be in the same order as a pre-order traversal of the binary tree.

Example 1:

Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]

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
    void flatten(TreeNode* root) {
        // base case
        if (root == NULL) {
            return;
        }
        
        // go to the leaf first
        flatten(root->left);
        flatten(root->right);
        
        // store left and right subtree into variable
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        
        // delete left subtree
        root->left = NULL;
        // replace right subtree with left subtree
        root->right = left;
        
        // pointer to traverse to the end of newly replaced right subtree
        TreeNode* p = root;
        while(p->right != NULL){
            p = p->right;
        }
        
        // join the initial right subtree to the end of new right subtree
        p->right = right;
    }
};
