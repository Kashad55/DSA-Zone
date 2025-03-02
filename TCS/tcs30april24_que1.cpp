#include<iostream>
#include<vector>
using namespace std;

struct basedata{
    int id;
    string name;
    int age;
    char grade;
    string gender;
};

int main(){
    basedata d;
    vector<basedata> db;
    int n;
    cout<<"Enter Number of students:";
    cin>>n;
    d.id=1;
    while(n>0){
        
        cout<<"Ener details for student "<<d.id;
        cout<<"\nName:";
        cin>>d.name;
        cout<<"Age:";
        cin>>d.age;
        cout<<"Grade (A/B/C,etc):";
        cin>>d.grade;
        cout<<"Gender (Male/ Female):";
        cin>>d.gender;

        db.push_back(d);
        d.id++;

        n--;
    }
    vector<string> old;
    double sum_g=0.0;
    int cnt=0;
    for(auto i:db){
        if(i.age>20) old.push_back(i.name);
        if(i.gender=="Female") {
            int alp=i.grade;
            sum_g+=alp;
            cnt++;
        }
    }

    cout<<"students with age greater than 20:";
    for(auto i:old) cout<<i<<" ";
    if(cnt==0) cout<<"no female student present";
    else   cout<<"\n Grade of female studnets:"<<sum_g/cnt;

    return 0;
}