Given the root of a binary tree, return the inorder traversal of its nodes' values.
  
Example 1:

Input: root = [1,null,2,3]
Output: [1,3,2]

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
 
// recursive solution
class Solution {
public:
    vector<int> res;
    
    void traverse(TreeNode* root){
        if(root == nullptr){
            return;
        }
        
        traverse(root->left);
        res.push_back(root->val);
        traverse(root->right);
        return;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        traverse(root);
        return res;
    }
};

// iterative with stack
class Solution {
public:
   
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        TreeNode* curr = root;
        
        // must check for curr != nullptr because curr is nullptr initially
        while(!st.empty() || curr != nullptr){
            if(curr != nullptr){
                st.push(curr);
                curr = curr->left;
            }
            else {
                curr = st.top();
                st.pop();
                res.push_back(curr->val);
                curr = curr->right;
            }
        }
        return res;
    }
};
