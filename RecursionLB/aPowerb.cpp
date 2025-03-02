#include <iostream>
using namespace std;
int power(int a, int b){
    //Base case
    if(b == 0)
        return 1;
    
    if(b == 1)
        return a;
    
    //Rec call
    int ans = power(a, b/2);
    if(b%2 == 0){
        return ans*ans;
    }
    else{
        return a*ans*ans;
    }

}
int main(){
    int a = 2, b = 10;
    cout<<power(a,b);

return 0;
}