Given the root of a binary tree, return the postorder traversal of its nodes' values.
  
Example 1:  
  
Input: root = [1,null,2,3]
Output: [3,2,1]

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
    vector<int> res;
    
    void traverse(TreeNode* root) {
        if(root == nullptr){
            return;
        }
        
        traverse(root->left);
        traverse(root->right);
        res.push_back(root->val);
        return;
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        traverse(root);
        return res;
    }
};
