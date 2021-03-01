Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

class Solution {
public:
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs){
            // rhs smaller means that smallest item should be popped first ?
            return lhs.second > rhs.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        
        for(int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
       
        priority_queue<pair<int,int>, vector<pair<int,int>>, mycomparison> prio_que;
        
        for(unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++){
            prio_que.push(*it);
            if(prio_que.size() > k){
                prio_que.pop();
            }
        }
        
        vector<int> res(k);
        for(int i = k - 1; i >= 0; i--){
            res[i] = prio_que.top().first;
            prio_que.pop();
        }
        
        return res;
    }
};
