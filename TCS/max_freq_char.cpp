#include<iostream>
#include<map>
using namespace std;
int main(){
    string ip="abcde";
    map<char,int> freq;
    for(auto i:ip){
        freq[i]++;
    }
    int max=0;
    char ans;
    for(auto i:freq){
        if(i.second>max) {
            max=i.second;
            ans=i.first;
        }
    }
    cout<<"max freq char is:"<<ans<<" with frq:"<<max;
    return 0;
}