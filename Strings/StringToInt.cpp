// Given a string, s, the objective is to convert it into integer format without utilizing any built-in functions. If the conversion is not feasible, the function should return -1.
#include <iostream>
using namespace std;
class Solution{
    public:
    int atoi(string s) {
        
        int num=0;
        int i=0;
        if(s[0]=='-')
        i++;
        
        while(i<s.length())
        {
            if(s[i]<'0' or s[i]>'9')
            return -1;
            
            num = num*10 + (s[i]-'0');
            i++;
        }
        
        if(s[0]=='-')
        num*=-1;
        
        return num;
    }
};
int main(){
    Solution obj;
    string s = "-123";
    string s1 = "25b";
    string s2 = "250";
    cout<<"Output = "<<obj.atoi(s)<<endl;
    cout<<"Output = "<<stoi(s);     //builin method of string

return 0;
}
/*In C++, characters are represented as integers based on their ASCII values. The ASCII value of '0' is 48. By subtracting the ASCII value of '0' from the ASCII value of s[i], you effectively convert the character digit to its numeric value.

Here's the breakdown:

If s[i] is '0', (s[i] - '0') evaluates to (48 - 48), which is 0.
If s[i] is '1', (s[i] - '0') evaluates to (49 - 48), which is 1.
If s[i] is '2', (s[i] - '0') evaluates to (50 - 48), which is 2.
... and so on.*/