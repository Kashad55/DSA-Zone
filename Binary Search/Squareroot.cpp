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
int main()
{
    int n=49, result;
    result = binarySearch(n);
    cout<<"Square root Of "<<n<<" = "<<result;
return 0;
}