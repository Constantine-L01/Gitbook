The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police. 

Example 1:

Input: root = [3,2,3,null,3,null,1]
Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
  
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
    vector<int> robTree(TreeNode* root) {
        if(root == nullptr) {
            return {0, 0};
        }
        
        vector<int> left = robTree(root->left);
        vector<int> right = robTree(root->right);
        
        int stealCur = root->val + left[0] + right[0];
        int noStealCur = max(left[0], left[1]) + max(right[0], right[1]);
        
        return {noStealCur, stealCur};
    }
    
    int rob(TreeNode* root) {
        vector<int> dp = robTree(root);
        return max(dp[0], dp[1]);
    }
};
