#include<iostream>
using namespace std;
int firstOcc(int arr[], int n, int key) {

    int s = 0, e = n-1;
    int ans = -1;
    while(s<=e) {
        int mid = s + (e-s)/2;

        if(arr[mid] == key){
            ans = mid;
            e = mid - 1;
        }
        else if(key > arr[mid]) {//Right me jao
            s = mid + 1;
        }
        else if(key < arr[mid]) {//left me jao
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }
    return ans;
}

int lastOcc(int arr[], int n, int key) {

    int s = 0, e = n-1;
    int ans = -1;
    while(s<=e) {
        int mid = s + (e-s)/2;

        if(arr[mid] == key){
            ans = mid;
            s = mid + 1;
        }
        else if(key > arr[mid]) {//Right me jao
            s = mid + 1;
        }
        else if(key < arr[mid]) {//left me jao
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }
    return ans;
}
int main()
{
    int array[9] = {1,3,3,3,3,3,5,6,7};
    cout<<"First occurence of 3 is at index "<<firstOcc(array, 9, 3)<<endl;
    cout<<"Last occurence of 3 is at index "<<lastOcc(array, 9, 3)<<endl;
    return 0;
}
