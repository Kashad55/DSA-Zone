#include<iostream>
#include<set>
using namespace std;

int main(){
    string s1="abccd";
    string s2="abcd";
    set<char>s1_set;   //Set:Sorted and Unique
    for(char c:s1){
        s1_set.insert(c);       //.insert and .emplace works same
    }

    set<char>s2_set;
    for(char c:s2){
        s2_set.insert(c);
    }

    string ans="";
    for(auto ch:s1_set){
        if(s2_set.find(ch)!=s2_set.end()){     //set.find(ch):if ch is not in the set, it'll return set.end() value
            ans+=ch;
        }
    }
    cout<<ans;
    


    return 0;
}