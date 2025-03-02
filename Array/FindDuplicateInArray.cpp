#include <iostream>
using namespace std;
int Duplicate(int arr[], int n){
    int ans=0;
    
    for(int i=0; i<n; i++){
        ans = ans ^ arr[i];
    }
    for(int i=0; i<n; i++){
        ans = ans ^ i;
    }
    return ans;
}
int main(){
    int a[6] = {5,2,1,2,3,4};
    int d = Duplicate(a,6);
    cout<<"Duplicate element : "<<d;

return 0;
} 