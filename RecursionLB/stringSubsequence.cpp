#include <iostream>
#include <vector>
using namespace std;
void subset(string str, string output, int i, vector<string> &ans){
    //Base case
    if(i >= str.size()){
        ans.push_back(output);
        return;
    }

    //exclude
    subset(str, output, i+1, ans);

    //include
    int element = str[i];
    output.push_back(element);
    subset(str, output, i+1, ans);
}
int main(){
    string str = "abc";
    string output;
    int i=0;
    vector<string> ans;
    subset(str, output, i, ans);

    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

return 0;
}

/*Input: abc
  Output: a ab abc ac b bc c
  Explanation :
  All possible subsequences of abc are :  
  " ", “a” , “b” , “c” , “ab” , “bc” , “ac”, “abc”*/