#include <iostream>
using namespace std;
int arraySum(int *arr, int size, int sum){
    //Base case
    if(size == 0){
        return sum;
    }
    sum += arr[0];
    return arraySum(arr+1, size-1, sum);
}
int arraySum2(int *arr, int size){
    //Base case
    if(size == 0){
        return 0;
    }
    if(size == 1){
        return arr[0];
    }
    int remainingPart = arraySum2(arr+1, size-1);
    int ans = arr[0] + remainingPart;
    return ans;
}
int arraySum3(int *arr, int size){
    if(size == 1) return arr[0];
    return arr[size-1] + arraySum3(arr, size-1); 
}
int main(){
    int arr[5] = {1,2,0,5,7};
    int size = 5;
    int sum = 0;
    cout<<"Sum of array is = "<<arraySum(arr, size, sum)<<endl;
    cout<<"Sum of array is = "<<arraySum2(arr, size)<<endl;
    cout<<"Sum of array is = "<<arraySum3(arr, size);
return 0;
}