Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set;
        unordered_set<int> nums_set(nums2.begin(), nums2.end());
        
        for(auto num: nums1){
            if(nums_set.find(num) != nums_set.end()){
                result_set.insert(num);
            }
        }
        
        return vector<int>(result_set.begin(), result_set.end());
    }
};
