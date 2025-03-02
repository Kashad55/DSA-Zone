#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
struct dict{
    string item;
    double price;
    int quanti;
};

int main(){
    vector<dict> d={{"a",0.2,2},{"b",0.75,5},{"c",1.2,8}};
    double ts=0;
    for(auto i:d){
        ts+=(i.price*i.quanti);
    }
    cout<<"total sum:"<<ts;

    double avg=ts/d.size();
    cout<<"average is:"<<avg;

    double mostps=0;
    string ans="";
    unordered_map<string,double> pc;
    for(auto i:d){
        pc[i.item]=i.price*i.quanti;
    }
    for(auto j:pc){
        if(j.second>mostps){
            mostps=j.second;
            ans=j.first;
        }
    }
    cout<<"most proitable is:"<<ans<<" with :"<<mostps;
    
  return 0;
}