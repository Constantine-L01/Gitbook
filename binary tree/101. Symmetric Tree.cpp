Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
  
Example 1:

Input: root = [1,2,2,3,4,4,3]
Output: true
  
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
    bool compare(TreeNode* left, TreeNode* right){
        if(left != nullptr && right == nullptr){
            return false;
        }
        else if(left == nullptr && right != nullptr) {
            return false;
        }
        else if(left == nullptr && right == nullptr) {
            return true;
        }
        else if(left->val != right->val) {
            return false;
        }
        
        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        return outside && inside;
    }
    
    bool isSymmetric(TreeNode* root) {
        return compare(root->left, root->right);
    }
};
