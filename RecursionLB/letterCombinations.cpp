#include <iostream>
#include <vector>
using namespace std;
void solve(string digits, string output, int i, vector<string> &ans, string mapping[]){
    //Base case
    if(i >= digits.length()){
        ans.push_back(output);
        return;
    }

    int number = digits[i] - '0';       //it produce int value
    string value = mapping[number];

    for(int idx=0; idx<value.length(); idx++){
        output.push_back(value[idx]);
        solve(digits, output, i+1, ans, mapping);
        output.pop_back();      //remove that char which is added before rec call -->Backtracking
    }
}
int main(){
    string digits = "23";
    vector<string> ans;
    string output= "";
    int i=0;
    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(digits, output, i, ans, mapping);

    for(auto i : ans){
        cout<<i<<endl;
    }
return 0;
}

/*  
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]*/