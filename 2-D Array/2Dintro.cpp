#include<iostream> 
using namespace std; 

bool isPresent(int arr[][3], int key, int row, int col) {

  for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            
            if( arr[row][col] == key) {
                return 1;
            }
            
        }
    }
    return 0;
}

//to print column wise sum
void colSum(int arr[][3], int row, int col) {
    cout << "Printing column wise Sum -> " << endl;
    for(int col=0; col<3; col++) {
        int sum = 0;
        for(int row=0; row<3; row++) {
            sum += arr[row][col];
        }
        cout << sum << " ";
    }

    cout << endl;
}


//to print row wise sum
void rowSum(int arr[][3], int row, int col) {
    cout << "Printing row wise Sum -> " << endl;
    for(int row=0; row<3; row++) {
        int sum = 0;
        for(int col=0; col<3; col++) {
            sum += arr[row][col];
        }
        cout << sum << " ";
    }

    cout << endl;
}

int largestRowSum(int arr[][3], int row, int col) {

    int maxi = 0;
    int rowIndex = -1;

    for(int i=0; i<row; i++) {
        int sum = 0;
        for(int j=0; j<col; j++) {
            sum += arr[i][j];
        }

        if(sum > maxi ) {
            maxi = sum;
            rowIndex = i;
        }
       
    }

    cout << "the maximum sum is " << maxi << endl;
    return rowIndex;
}

int main() {

    //create 2 d array
    int arr[3][3];
    //int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,14,16};
    //int arr[3][4] = {{1,11,111,1111}, {2,22,222,2222}, {3,33,333,3333}};

    cout << "Enter the elements "  ;
    //taking input -> row wise input
    for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            cin >> arr[row][col];
        }
    }


/*
//taking input -> col wise input
    for(int col=0; col<4; col++) {
        for(int row=0; row<3; row++) {
            cin >> arr[row][col];
        }
    }

*/

    //print 
    cout << "Printing the array " << endl;
    for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }

    cout <<"Enter the element to search :" ;
    int key;
    cin >> key;

    if(isPresent(arr, key, 3, 3)) {
        cout <<"Element found !" << endl;
    }
    else{
        cout <<"Element Not Found !" << endl;
    }


    rowSum(arr, 3, 3 );
   int ansIndex = largestRowSum(arr,3,3);
   cout << " Max sum row is at index :" << ansIndex << endl;

    return 0;
}