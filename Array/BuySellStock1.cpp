#include <iostream>
#include <vector>
using namespace std;
//Brute     O(N2)  |  O(1)
int maximumProfit1(vector<int> arr){
    int maxProfit=0;
    int n=arr.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            maxProfit = max(maxProfit, arr[j]-arr[i]);
        }
    }
    return maxProfit;
}
//Better O(N)  |  O(N)
int maximumProfit2(vector<int> arr){          //[7,1,5,3,6,4]
    int n = arr.size();
    int aux[n];
    int maxSoFar=arr[n-1];
    // Populate the aux array with maximum values from right to left
    for(int i=n-1; i>=0; i--){
        maxSoFar = max(maxSoFar, arr[i]);
        aux[i] = maxSoFar;                     //[7,6,6,6,6,4]
    }
    int maxProfit=0;
    for(int i=0; i<n; i++){
        maxProfit = max(maxProfit, aux[i]-arr[i]);
    }
    return maxProfit;
}
//Optimal   O(N)  |  O(1)
int maximumProfit3(vector<int> arr){
    int maxProfit = 0;
    int minSoFar = arr[0];
    for(int i=1; i<arr.size(); i++){
        int cost = arr[i] - minSoFar;
        maxProfit = max(maxProfit, cost);
        minSoFar = min(minSoFar, arr[i]);
    }
    return maxProfit;
}
int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout<<"Maximum profit = "<<maximumProfit3(prices)<<endl;
return 0;
}



/*You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.*/