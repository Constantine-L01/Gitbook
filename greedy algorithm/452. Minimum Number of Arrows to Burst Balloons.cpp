There are some spherical balloons spread in two-dimensional space. For each balloon, provided input is the start and end coordinates of the horizontal diameter. Since it's horizontal, y-coordinates don't matter, and hence the x-coordinates of start and end of the diameter suffice. The start is always smaller than the end.

An arrow can be shot up exactly vertically from different points along the x-axis. A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend. There is no limit to the number of arrows that can be shot. An arrow once shot keeps traveling up infinitely.

Given an array points where points[i] = [xstart, xend], return the minimum number of arrows that must be shot to burst all balloons.

Example 1:

Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and another arrow at x = 11 (bursting the other two balloons).

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0) {
            return 0;
        } 
        
        // sort based on the starting position of the balloons.
        sort(points.begin(), points.end(), cmp);
        
        int result = 1;
        
        for(int i = 1; i < points.size(); i++) {
            // current balloon's starting position is more than the farthest overlapping region of all the previous balloons
            if(points[i][0] > points[i-1][1]) {
                result++;
            }
            else {
                // the current ballon could be shot together with the previous ballons and thus update the farthest overlapping region
                points[i][1] = min(points[i][1], points[i-1][1]);
            }            
        }
        
        return result;        
    }
};
