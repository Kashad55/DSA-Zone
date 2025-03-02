#include <iostream>
using namespace std;
string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
void digitSays(int n){
    //Base case
    if(n == 0){
        return;
    }
    int digit = n % 10;
    // cout<<arr[digit]<<" ";       //op: two one four

    n = n/10;
    digitSays(n);
    
    cout<<arr[digit]<<" ";          //op: four one two
}
int main(){
    digitSays(412);

return 0;
}