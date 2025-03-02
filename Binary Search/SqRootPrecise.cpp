#include <iostream>
using namespace std;
//for very large no. use (long long int) instead of (int) only.
int binarySearch(int n){
    int s=0;
    int e=n;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e){
        int sq = mid*mid;

        if(sq == n)
        return mid;
        
        if(sq < n){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid -1;
        }
        mid = s + (e-s)/2;

    }
    return ans;
} 
//WKT, Float = 4 bytes and double = 8 bytes ==>we use double
double morePrecision(int n, int precision, int tempSol){
    double factor = 1;
    double ans = tempSol;

    for(int i=0; i<precision; i++){
        factor = factor / 10;

        for(double j=ans; j*j<n; j=j+factor){
            ans = j;
        }
    }
    return ans;
}
int main()
{
    int n=55;
    int tempSol = binarySearch(n);
    double result = morePrecision(n, 4, tempSol);
    cout<<"Square root Of "<<n<<" = "<<result;
return 0;
}