Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]

Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

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
    TreeNode* build(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd) {
        if (inStart > inEnd) {
            return NULL;
        }
        
        int rootVal = postorder[postEnd];
        int index = 0;
        
        for (int i = inStart; i <= inEnd; i++) {
            if (rootVal == inorder[i]) {
                rootVal = inorder[i];
                index = i;
                continue;
            }
        }
        
        int leftSize = index - inStart;
        
        TreeNode* root = new TreeNode(rootVal);
        root->left = build(inorder, inStart, index - 1, postorder, postStart, postStart + leftSize - 1);        
        // cannot use postStart + leftSize + 1 for postorder because the root value is at the last spot, but not between left region and right region. 
        root->right = build(inorder, index + 1, inEnd, postorder, postStart + leftSize, postEnd - 1);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};
