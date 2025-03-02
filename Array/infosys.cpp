#include <iostream>
using namespace std;

int main(){
    int arr[] = {1, 4, 20, 3, 10, 5}, sum = 18;
    int n=6;
    // for(int i=0; i<n; i++){
    //     int tsum = arr[i];
    //     for(int j=i+1; j<6; j++){
    //         tsum += arr[j];
    //         if(tsum == sum){
    //             cout<<i<<" "<<j<<endl;
    //             return 0;
    //         }
    //     }
    // }
    // int arr[] = {1, 3, 4, 7, 8, 10}, sum = 25;  //Sorted array
    int i=0, j=0;
    int tsum = 0;
    while(j<=n){
        if(tsum > sum){
            tsum -= arr[i];
            i++;
            j--;
        }
        else tsum += arr[j];
        // cout<<i<<" "<<j<<endl;
        // cout<<tsum<<endl;
        if(tsum == sum){
            cout<<i<<" "<<j;
            break;
        }
        j++;
    }
}
/*Q2-Given an array arr[] of non-negative integers and an integer sum, find a subarray that adds to a given sum.
Note: There may be more than one subarray with sum as the given sum, print first such subarray. 
Examples: 
Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33
Output: Sum found between indexes 2 and 4*/


/*Q1-Write a program to accept an array i.e:- ['abc', 'cba', 'dell', 'ledd', 'boo'] 
and convert to object in this format {dell : [dell, ledd], abc : [abc, cba], boo}*/