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

// Iterative with queue
class Solution {
public:    
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) {
            return true;
        }
        queue<TreeNode*> que;
        
        if(root != nullptr){
            que.push(root->left);
            que.push(root->right);
        }
        
        while(!que.empty()){
            TreeNode* leftNode = que.front(); que.pop();
            TreeNode* rightNode = que.front(); que.pop();
            
            if(!leftNode && !rightNode){
                continue;
            }
            
            if(!leftNode || !rightNode || (leftNode->val != rightNode->val)){
                return false;
            }
            
            que.push(leftNode->left);
            que.push(rightNode->right);
            que.push(leftNode->right);
            que.push(rightNode->left);               
        }
        return true;        
    }
};

// Iterative with stack
class Solution {
public:    
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) {
            return true;
        }
        stack<TreeNode*> st;
        
        if(root != nullptr){
            st.push(root->left);
            st.push(root->right);
        }
        
        while(!st.empty()){
            TreeNode* leftNode = st.top(); st.pop();
            TreeNode* rightNode = st.top(); st.pop();
            
            if(!leftNode && !rightNode){
                continue;
            }
            
            if(!leftNode || !rightNode || (leftNode->val != rightNode->val)){
                return false;
            }
            
            st.push(leftNode->left);
            st.push(rightNode->right);
            st.push(leftNode->right);
            st.push(rightNode->left);               
        }
        return true;        
    }
};
