Given a binary tree, we install cameras on the nodes of the tree. 

Each camera at a node can monitor its parent, itself, and its immediate children.

Calculate the minimum number of cameras needed to monitor all nodes of the tree.

Example 1:

Input: [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.

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
    int result = 0;    
    // 0: not covered 
    // 1: got camera
    // 2: covered
  
    int traverse(TreeNode* root) {
        if(root == nullptr){
            return 2;
        }
        
        int left = traverse(root->left);
        int right = traverse(root->right);
        
        if(left == 0 || right == 0){
            result++;
            return 1;
        }
        
        if(left == 2 && right == 2){
            return 0;
        }
        
        if(left == 1 || right == 1){
            return 2;
        }
        // just for compiler, will never execute
        return -1;
    }
    
    int minCameraCover(TreeNode* root) {        
        if(traverse(root) == 0){
            result++;
        }
        
        return result;
    }
};

class Solution {
public:
    int result = 0;
    
    int traverse(TreeNode* root) {
        if(root == nullptr){
            return 2;
        }
        
        int left = traverse(root->left);
        int right = traverse(root->right);
        
        if(left == 0 || right == 0){
            result++;
            return 1;
        }        
        else if(left == 2 && right == 2){
            return 0;
        }        
        else return 2;        
    }
    
    int minCameraCover(TreeNode* root) {
        if(traverse(root) == 0){
            result++;
        }        
        return result;
    }
};
