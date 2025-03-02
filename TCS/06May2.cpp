#include <iostream>
using namespace std;
bool isPrime(int n){
    for(int i=2; i<n; i++){
        if(n%i == 0 && n!=2){
            return false;
        }
    }
    return true;
}
int countPrime(int a, int b){
    int c=0;
    for(int i=a; i<=b; i++){
        if(isPrime(i)){
            int num = i;
            int sum=0;
            while(num>0){
                sum += (num%10);
                num /= 10;
            }
            if(isPrime(sum)) c++;
        }
    }
    return c;
}
int main(){
    int a=10, b=30;
    cout<<"No of prime no's whose sum is also prime = "<<countPrime(a,b);

return 0;
}