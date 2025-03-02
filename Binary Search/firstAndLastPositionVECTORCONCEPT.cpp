#include<iostream>
#include<vector>
using namespace std;
//BY THE LOGIC OF BINARY Search
int firstOcc(vector<int>& arr, int n, int key) {

    int s = 0, e = n-1;
    int ans = -1;
    int mid = s + (e-s)/2;
    while(s<=e) {

        if(arr[mid] == key){
            ans = mid;
            e = mid - 1;
        }
        else if(key > arr[mid]) {//Right me jao
            s = mid + 1;
        }
        else {//left me jao
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }
    return ans;
}

int lastOcc(vector<int>& arr, int n, int key) {

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
//PAIR CONCEPT IN C++
// pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
// {
//     pair<int,int> p;
//     p.first = firstOcc(arr, n, k);
//     p.second = lastOcc(arr, n, k);
    
//     return p;
// }
int main()
{
   vector<int> array = {1,3,3,3,3,3,5,6,7};
    cout<<"First occurence of 3 is at index "<<firstOcc(array, 9, 3)<<endl;
    cout<<"Last occurence of 3 is at index "<<lastOcc(array, 9, 3)<<endl;

return 0;
}