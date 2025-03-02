#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<int> arr3 = {4,2,9,7,5,1};    
    sort(arr3.begin(), arr3.end());
    cout<<"Testing of sort() fx :"<<endl;
    for(int i=0; i<arr3.size(); i++){
        cout<<arr3[i]<<" ";
    }

return 0;
}