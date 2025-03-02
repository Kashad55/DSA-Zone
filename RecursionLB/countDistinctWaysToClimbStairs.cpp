#include <iostream>
using namespace std;
int countWays(int nStairs){
    //Base case
    if(nStairs < 0) return 0;
    if(nStairs == 0) return 1;

    //R.C
    return countWays(nStairs-1) + countWays(nStairs-2);
}
int main(){
    cout<<"Distinct ways to climb 4 stairs = "<<countWays(4)<<endl;
    cout<<"Distinct ways to climb 5 stairs = "<<countWays(5)<<endl;

return 0;
}