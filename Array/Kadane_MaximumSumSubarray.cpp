#include <iostream>
#include <vector>
using namespace std;

//Brute Method  O(N3)
int MaxSubSum(int arr[], int n){
    int maxi = INT16_MIN;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int sum=0;
            for(int k=i; k<j; k++){
                sum+=arr[k];
            }
            maxi = max(sum, maxi);
        }
    }
    return maxi;
}
//Better Method  O(N2)
int MaxSubSum2(int arr[], int n){
    int maxi = INT16_MIN;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            maxi = max(sum, maxi);
        }
    }
    return maxi;
}

//Kadane's Algorithm  -> Maximum Subarray Sum
int MaxSubSum3(int arr[], int n){
    int sum=0, max = INT16_MIN;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum > max){
            max=sum;
        }
        if(sum < 0){
            sum=0;
        }
    }
    return max;
}
//Kadane's Algorithm  -> Maximum Subarray
vector<int> MaxSubarray(int arr[], int n){
    vector<int> v;
    int sum=0, max = INT16_MIN;
    int start=0, s=0, e=0;
    for(int i=0; i<n; i++){
        if(sum == 0) start=i;
        sum += arr[i];
        if(sum > max){
            max=sum;
            s=start;
            e=i;
        }
        if(sum < 0){
            sum=0;
        }
    }
    for(int i=s; i<=e; i++){
        v.push_back(arr[i]);
    }
    return v;
}

int main(){
    int arr[8] = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout<<"Maximum Subarray sum = "<<MaxSubSum3(arr, 8);

    cout<<"\nMaximum Subarray : ";
    vector<int> ms = MaxSubarray(arr, 8);
    for(int i=0; i<ms.size(); i++){
        cout<<ms[i] <<" ";
    }

return 0;
}