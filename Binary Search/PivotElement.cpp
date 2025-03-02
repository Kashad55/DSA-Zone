#include <iostream>
#include<vector>
using namespace std;

    //brute method TC: O(N) 
    int pivot2(vector<int> arr){
        for(int i=1; i<arr.size()-1; i++){
            if(arr[i]<arr[i-1] && arr[i]<arr[i+1]){
                return i;
            }
        }
        return arr.size()-1;
    }
    //Optimized method ie BS TC: O(logN)
    int pivot(vector<int> a){
        int s=0, e = a.size()-1;
        int mid = s + (e-s)/2;
        while(s<e){
            if(a[mid] >= a[0])
                s = mid + 1;
            else
                e = mid;
            mid = s + (e-s)/2;
        }
        return s;
        // return e; //This also works bcoz at the end both(s & e) were at same index
    }
int main()
{
    // vector<int> arr = {10, 17, 1, 3, 8};
    vector<int> arr = {5,6,7,8,9,10,1,2,3};
    // vector<int> arr = {1, 3, 8, 10, 17};
    // vector<int> arr = {3,8,10,17,1};
    int p = pivot2(arr);
    cout<<"Pivot element is at index-"<<p<<" = "<<arr[p];

return 0;
}
