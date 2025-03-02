#include <iostream>
#include <vector>
using namespace std;
//Recursion
int solve(vector<int> &cost, int n){
    //Base case
    if(n == 0) return cost[0];
    if(n == 1) return cost[1];

    int ans = cost[n] + min(solve(cost, n-1), solve(cost, n-2));
    return ans;
}
//Recursion + Memoization
int solve2(vector<int> &cost, int n, vector<int> &dp){
    //Base case
    if(n == 0) return cost[0];
    if(n == 1) return cost[1];

    //Step-3
    if(dp[n] != -1){
        return dp[n];
    }

    //Step-2
    dp[n] = cost[n] + min(solve2(cost, n-1, dp), solve2(cost, n-2, dp));
    return dp[n];
}
//Tabulation (Bottom-Up)
int solve3(vector<int> &cost, int n){
    //Step-1 : Creation
    vector<int> dp(n+1);
    //Step-2 : Base case analyze
    dp[0] = cost[0];
    dp[1] = cost[1];
    //Step-3 : 
    for(int i=2; i<n; i++){
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    }
    return min(dp[n-1], dp[n-2]);
}
//Space Optimisation
int solve4(vector<int> &cost, int n){
    int prev2 = cost[0];
    int prev1 = cost[1];

    for(int i=2; i<n; i++){
        int curr = cost[i] + min(prev1, prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    return min(prev1, prev2);
}
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();

    // return min(solve(cost, n-1), solve(cost, n-2));

    //Step-1
    vector<int> dp(n+1, -1);    
    return min(solve2(cost, n-1, dp), solve2(cost, n-2, dp));

    // return solve3(cost, n);

    // return solve4(cost, n);

    /*int i=0, c=0;
    if(cost[0] > cost[1] || n==3) i++;

    while(i<n-1){
        if(cost[i] < cost[i+1]){
            c += cost[i];
        }
        else{
            c += cost[i+1];
            i++;
        }
        i++;
    }
    return c;*/
}
int main(){
    vector<int> cost1 = {10,15,20};
    vector<int> cost2 = {1,100,1,1,1,100,1,1,100,1};
    cout<<"Minimun cost to climb stairs = "<<minCostClimbingStairs(cost1)<<endl;
    // cout<<"Minimun cost to climb stairs = "<<minCostClimbingStairs(cost2)<<endl;
return 0;
}

/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. 
Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
*/