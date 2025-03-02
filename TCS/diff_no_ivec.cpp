#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    // vector<int> a={1,2,1,3,4,5,1};
    vector<int> a={4,4,4};
    int n=a.size();
    int count_1ele=count(a.begin(),a.end(),a[0]);
    cout<<"remain value is:"<<n-count_1ele;
    return 0;
}