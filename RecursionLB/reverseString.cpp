#include <iostream>
using namespace std;
void reverse(string &str, int i, int j){
    //Base case
    if(i>j) return;

    swap(str[i], str[j]);
    i++, j--;
    reverse(str, i, j);
}
//Using one pointer ie i-only
void reverse2(string &str, int i){
    //Base case
    if(i < str.size()/2) return;

    // int i = str.length()-n-1;
    int j = str.length()-i-1;       //(n-i-1)
    swap(str[i],str[j]);

    i = i-1;
    reverse2(str, i);
}
int main(){
    string str = "Kashad";
    int n = str.length();
    // reverse(str, 0, n-1);
    reverse2(str, n-1);
    cout<<str<<endl;

return 0;
}