On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1. 

Example 1:

Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int first = cost[0];
        int second = cost[1];
        //just return the smaller first or second stairs if the number of stairs is less than or equal to 2
        if (cost.size() <= 2) return min(first, second);
        int curr = 0;
        // 1 2 4 2
        // curr = 4 + min(1,2)
        // first = 2
        // second = 5
        // can see that if the previous selection of 2nd element is not optimal, the current iteration will select the total amount deducted the 2nd element.
        for(int i = 2; i < cost.size(); i++) {
            curr = cost[i] + min(first, second);
            first = second;
            second = curr;
        }
        
        return min(first, second);
    }
};

// recursion ==================================================

class RecursionSolution {
    public int minCostClimbingStairs(int[] cost) {
        // GOAL: min cost from 0 to n-th
        // constraint one or two steps
        int n = cost.length;
        return Math.min(dfs(cost, n-2), dfs(cost, n-1));
    }
    
    private int dfs(int[] cost, int i) {
        if (i == 0 || i == 1) return cost[i];
        // by this, the previous two element will contain the optimal solution to reach it. The current i element = i value + selected i-1 or i-2 optimal value, and i + 1 will
        // consider the optimal solution of the unselected or the i element + selected. No point in consider more than 2 distance, since maximum step is 2.
        return Math.min(dfs(cost, i-1), dfs(cost, i-2)) + cost[i];
    }
}

// ==================================================
