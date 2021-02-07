You are given an integer array nums with no duplicates. A maximum binary tree can be built recursively from nums using the following algorithm:

    Create a root node whose value is the maximum value in nums.
    Recursively build the left subtree on the subarray prefix to the left of the maximum value.
    Recursively build the right subtree on the subarray suffix to the right of the maximum value.

Return the maximum binary tree built from nums.

Example 1:

Input: nums = [3,2,1,6,0,5]
Output: [6,3,5,null,2,0,null,null,1]
Explanation: The recursive calls are as follow:
- The largest value in [3,2,1,6,0,5] is 6. Left prefix is [3,2,1] and right suffix is [0,5].
    - The largest value in [3,2,1] is 3. Left prefix is [] and right suffix is [2,1].
        - Empty array, so no child.
        - The largest value in [2,1] is 2. Left prefix is [] and right suffix is [1].
            - Empty array, so no child.
            - Only one element, so child is a node with value 1.
    - The largest value in [0,5] is 5. Left prefix is [0] and right suffix is [].
        - Only one element, so child is a node with value 0.
        - Empty array, so no child.
        
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
    TreeNode* constructRoot(vector<int>& nums, int lo, int hi) {
        if (lo > hi) {
            return NULL;
        }
        
        int max = -1;
        int index = -1;
        // find the largest element in current subarray
        for(int i = lo; i <= hi; i++) {
            if(max < nums[i]){
                index = i;
                max = nums[i];
            }            
        }
        TreeNode* root = new TreeNode(max);
        // must use lo and hi because need to consider the left subtree of current right subtree or right subtree of current left subtree. 
        root->left = constructRoot(nums, lo, index - 1);
        root->right = constructRoot(nums, index + 1, hi);
        
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructRoot(nums, 0, nums.size() - 1);
    }
};


// Solution by using Monotone Stack
class Solution {
public:
    TreeNode*  constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> stk;
        for (int i = 0; i < nums.size(); i++) 
        {
            TreeNode* cur = new TreeNode(nums[i]);
            // Descending order, thus will pop out numbers smaller than the current number, then assign the largest popped out number as the left subtree of current number. 
            while(!stk.empty() && stk.back()->val < nums[i]) {
                cur->left = stk.back();
                stk.pop_back();
            }
            // The current number will be assigned as the right subtree of the top element of the stack.
            if (!stk.empty()) {
                stk.back()->right = cur;
            }
            // eventually push the current number into the stack. 
            stk.push_back(cur);
        }
        // return the root
        return stk.front();
    }
};
