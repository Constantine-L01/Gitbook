Given the root of a binary tree, return the preorder traversal of its nodes' values.
  
Example 1:

Input: root = [1,null,2,3]
Output: [1,2,3]

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
 
// recursive
class Solution {
public:
    vector<int> res;
    void traverse(TreeNode* root) {
        if(root == nullptr){
            return;
        }
        
        res.push_back(root->val);
        traverse(root->left);
        traverse(root->right);     
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        traverse(root);
        return res;
    }
};
