You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

//better solution with less space used
class Solution {
public:
    int climbStairs(int n) {
        
        // initially, the currentstep is first stair, oneStep means the move of climbing the stair, twoStep means the move of moving to right and climbing the stair. 1 for oneStep, 
        // 0 for twoStep because it is not possible
        int oneStepToReachDest = 1;
        int twoStepToReachDest = 0;     
        int currentStep = 0;
        
        // At first iteration, currentStep is 1 because only action oneStep is possible. At second iteration, twoStep = oneStep and oneStep = first iteration's currentStep
        for(int i = 1; i <= n; i++) {
            currentStep = oneStepToReachDest + twoStepToReachDest;
            twoStepToReachDest = oneStepToReachDest;
            oneStepToReachDest = currentStep;
        }
        
        return currentStep;
    }
};

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        
        vector<int> steps(n, 0);
        
        steps[0] = 1;
        steps[1] = 2;     
        
        for(int i = 2; i < n; i++) {
            steps[i] = steps[i-1] + steps[i-2];
        }
        
        return steps[n-1];
    }
};
