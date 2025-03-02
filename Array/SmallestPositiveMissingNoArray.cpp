#include <iostream>
using namespace std;
int missingNumber(int arr[], int n){ 
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(arr[i]>arr[j]){
                    int k = arr[i];
                    arr[i] = arr[j];
                    arr[j] = k;
                }
            }
            
        }
        int count=1;
       for (int i=0;i<n;i++){
           if (arr[i]==count)
           count++;
       }
       return count;
}
int main(){
    int a[5] = {-2,3,-4,1,6};
    int miss = missingNumber(a, 5);
    cout<<"Smallest Positive Missing no. is: "<<miss<<endl;

return 0;
}