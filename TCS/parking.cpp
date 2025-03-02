// task is to find nrow in matrix of 01 with matx 1s
// M=row no   N=no of col
#include<iostream>
using namespace std;

int main(){
    int m=3, n=4;
    int arr[m][n]={{0,1,0,0},{1,1,0,1},{1,1,1,1}};

    int max_car_inr=0;
    int rownum=-1;
    for(int i=0;i<m;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            cnt+=arr[i][j];
        }
        if(cnt>max_car_inr){
            max_car_inr=cnt;
            rownum=i;
        }
    }

    cout<<"row "<<rownum<<" has max 1s";

    return 0;
}