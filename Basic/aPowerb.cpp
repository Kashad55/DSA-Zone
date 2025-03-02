#include <iostream>
using namespace std;

int main(){
    int a=5, b=3;
    int ans = 1;
    for(int i=0; i<b; i++){
        ans = ans * a; 
    }
    cout<<ans;

return 0;
}