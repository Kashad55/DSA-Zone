#include<bits/stdc++.h>
using namespace std;

string orderSeq(string s, int cnt){
    // string str="";
    // vector<int> v;
    // int arr[200]={0};
    // int n=s.size();
    // for(char i : s){
    //     arr[i]++;
    // }
    // for(int i=0; i<200; i++){
    //     if(arr[i] >= cnt){
    //         str += i;
    //     }
    // }
    // return str;

    map<char, int> freq;
    for(char i : s){
        freq[i]++;
    }
    int n=s.length();
    string str = "";
    for(auto i : freq){
        if(i.second >= cnt){
            str+=i.first;
        } 
    }
    /*// without disturbing the order ->method-1
    for (char c : s) {
        if (freq[c] >= cnt) {
            // Add the character to the result and set its frequency to -1 to avoid adding it again
            str += c;
            freq[c] = -1; // Mark as processed
        }
    }
    // without disturbing the order ->method-2
    for(char i : s){
        freq[i]++;
        if(freq[i] >= cnt){
            str += i;
            freq[i] = INT16_MIN;
        }
    }*/
    // sort(str.begin(), str.end());    //in map, keys are already sorted
    return str;
}

int main(){
    string s = "ccbaappmfff";
    cout<<"Given String : "<<s<<endl;
    int mincount = 2;
    string str = orderSeq(s,mincount);
    cout<<str;

return 0;
}