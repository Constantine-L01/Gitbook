Given a collection of intervals, find the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Example 1:

Input: [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of intervals are non-overlapping



// this solution check for region to be removed
class Solution {
public:
 
    static bool sortcol( const vector<int>& v1, const vector<int>& v2 ) { 
        // sort right boundary by ascending order
        return v1[1] < v2[1]; 
    } 
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {    
        
        if(intervals.size()<1){
            return 0;
        }
        int operations = 0;        
        sort(intervals.begin(), intervals.end(), this->sortcol);
         int previous = intervals[0][0];
        
        for(auto i: intervals){
            cout << i[0] << " " << i[1] << endl;
            cout << previous << endl;
            // if current region left boundary is smaller than previous region then this region should be removed
            if(i[0] < previous){
                operations++;
            }
            else{
                // current region is not overlaps with previous region as some regions between current and previous have been removed.
                previous = i[1];
            }
        }        
        return operations;
    }
};
