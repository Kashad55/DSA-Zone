#include<iostream>
#include<vector>
using namespace std;
//Here we use priviously discussed pivot element concept===================>>>
int getPivot(vector<int>& arr, int n) {

    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e) {

        if(arr[mid] >= arr[0])
        {
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int binarySearch(vector<int>& arr, int s, int e, int key) {
    int mid = s + (e-s)/2;
    while(s <= e) {

        if(arr[mid] == key) {
            return mid;
        }

        //go to right wala part
        if(key > arr[mid]) {
            s = mid + 1;
        }
        else{ //key < arr[mid]
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }
    return -1;
}



int main()
{
    vector<int> arr = {7,9,1,2,3};   //Rotated Array
    int n=5;
    int key=2;
    int k=key;
    int pivot = getPivot(arr, 5);
    if( k >= arr[pivot] && k <= arr[n-1])
    {//BS on second line
        key =  binarySearch(arr, pivot, n-1, k);
    }
    else
    {//BS on first line
        key =  binarySearch(arr, 0, pivot - 1, k);
    }
    cout<<"Element found at index = "<<key;
}
