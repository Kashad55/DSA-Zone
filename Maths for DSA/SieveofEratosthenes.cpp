#include<iostream>
using namespace std;

void sieve(int n) {
    int prime[n];
    // mark (TRUE = 1) for every number
    for(int i=2;i<=n;i++){
        prime[i]=1;
    }

    for(int i = 2; i<=n; i++) {
        if(prime[i]){
            //iske saare multiple mark krde - non prime (false = 0)
            for(int j = 2*i; j<=n; j+=i){
                prime[j] = 0;   
            }
        }
    }
    prime[0] = prime[1] = 0;
    cout<<"Prime no. upto "<<n<<" are : ";
    for(int i=0; i<=n; i++){
        if(prime[i])
        cout<<i<<" ";
    }
}

int main() {
    int n;
    cout<<"Enter no.:";
    cin >> n;
    sieve(n);
    
    return 0;
}