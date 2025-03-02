#include <iostream>
#include <vector>
using namespace std;
//Recursion + Memoization   O(N) | O(2N)
int fib(int n, vector<int> &dp){
    //Base case
    if(n<=1) return n;

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = fib(n-1, dp) + fib(n-2, dp);
    return dp[n];
}
int main(){
    int n=6;
    vector<int> dp1(n+1, -1);
    cout<<n<<"th Fibonacci no is : "<<fib(n, dp1)<<endl;  //Fib series starting from 1 1 2 3 5 ........

//Tabulation    O(N) | O(N)
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout<<n<<"th Fibonacci no is : "<<dp[n]<<endl;

//Space Optimised soln  O(N) | O(1)
    int prev1 = 1;
    int prev2 = 0;
    for(int i=2; i<=n; i++){
        int curr = prev1 + prev2;
        //Shift logic
        prev2 = prev1;
        prev1 = curr;
    }
    cout<<n<<"th Fibonacci no is : "<<prev1;  //Fib series starting from 1 1 2 3 5 ........

return 0;
}