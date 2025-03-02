#include<iostream>
using namespace std;

void print(int *p) {

    cout <<"Inside print() :"<< *p << endl; 

}

void update(int *p) {

//    p = p + 1;
   cout << "inside update() : "<< p <<endl;
   *p = *p + 1;

}

int getSum(int *arr, int n) {

    cout << endl << "Size of array : " << sizeof(arr) << endl;

    int sum = 0;
    for(int i=0;i<n;i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
  
    int value = 5;
    int *p = &value;

    print(p);
    cout <<"Before update : " << *p << endl;
    update(p);
    cout <<"After update : " << *p << endl;
    

    int arr[6] = {1,2,3,4,5,8};

    cout << "Sum is " << getSum(arr+3 ,3) << endl ;  

    return 0;
}
