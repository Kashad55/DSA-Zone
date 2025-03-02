#include<iostream>
using namespace std;

int main(){
    string name="geeKsForGeekS";
    cout<<"string before:"<<name;
    for(int i=0;i<name.length();i++){
        if(islower(name[i])){
            name[i]=toupper(name[i]);
        }else if(isupper(name[i])){
            name[i]=tolower(name[i]);
        }
    }

    cout<<"\nNew string is:"<<name;
    return 0;
}