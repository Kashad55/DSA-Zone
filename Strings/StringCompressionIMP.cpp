#include <iostream>
#include <vector>
using namespace std;
int compress(vector<char>& chars) {
    int i=0;
    int ansIndex = 0;
    int n = chars.size();
    
    while(i<n){
        int j = i+1;
        while(j<n && chars[i]==chars[j]){
            j++;
        }
        //It means traversed or new char encountered
        
        chars[ansIndex++] = chars[i];
        int count = j-i;
        //Convert counting into single digit and saving it in answer
        if(count > 1){
            string cnt = to_string(count);
            for(char ch : cnt){
                chars[ansIndex++] = ch;
            }
        }
        i=j;   //Move to the new character
    }
    return ansIndex;
}

int main(){
    vector<char> chars = {'a','a','b','b','c','c','c'};
    cout<<compress(chars);
}
//EXPECTED O/P = a2b2c3 ie.=6