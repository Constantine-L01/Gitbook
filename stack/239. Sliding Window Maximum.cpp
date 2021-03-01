You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

class Solution {
public:
    class MyQueue{
    public:
        deque<int> que;
        void pop(int value){
            if(!que.empty() && que.front() == value){
                que.pop_front();
            }
            return;
        }
        void push(int value){
            while(!que.empty() && value > que.back()){
                que.pop_back();
            }
            que.push_back(value);
            return;
        }
        int front(){
            return que.front();
        }
    };    
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> res;
        
        for(int i = 0; i < k; i++){
            que.push(nums[i]);
        }
        res.push_back(que.front());
        
        for(int i = k; i < nums.size(); i++){
            // pop first because the largest element of previous iteration has been recorded and the loop invariants maintain.
            que.pop(nums[i - k]);
            que.push(nums[i]);
            res.push_back(que.front());
        }
        
        return res;
    }
};  
