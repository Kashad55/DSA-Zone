#include <iostream>
using namespace std;
string name[10];
int cls[10];
char sec[10];
int age[10];
int p=0;
class Student{
    public:
    void stddet(){
        cout<<"Name \tClass \tSection \tAge"<<endl;
        for(int i=0; i<p; i++){
            cout<<name[i]<<"\t"<<cls[i]<<"\t"<<sec[i]<<"\t"<<age[i]<<endl;
        }
    }
};
int main(){
    int n;
    cout<<"Enter the no. of Students : ";
    cin>>n;
    while(p<n){
        cout<<"Enter name, class, section and age : ";
        cin>>name[p]>>cls[p]>>sec[p]>>age[p];
        p++;
    }
    Student obj;
    obj.stddet();
    return 0;
}