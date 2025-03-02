#include <iostream>
#include <vector>
using namespace std;
//1.print all the subseq whoose sum(el) == sum, parameterised way
void printSS(int i, vector<int> &ds, int s, int sum, int arr[], int n){
    if(i == n){      //use(i >= n) for safe run
        if(s == sum){
            for(auto it : ds) cout<<it<<" ";
            cout<<endl;
        }
        return;
    }
    ds.push_back(arr[i]);
    s += arr[i];
    printSS(i+1, ds, s, sum, arr, n);

    s -= arr[i];
    ds.pop_back();
    
    //not picked
    printSS(i+1, ds, s, sum, arr, n);
}
//2.It'll return only 1 subsequence (return true or false and avoid further recursion call if u get true)
bool printSS1(int i, vector<int> &ds, int s, int sum, int arr[], int n){
    if(i == n){
        //condn satisfied
        if(s == sum){
            for(auto it : ds) cout<<it<<" ";
            cout<<endl;
            return true;
        }
        //condn not satisfies
        return false;
    }
    ds.push_back(arr[i]);
    s += arr[i];
    if(printSS1(i+1, ds, s, sum, arr, n)) return true;

    s -= arr[i];
    ds.pop_back();
    
    //not picked
    if(printSS1(i+1, ds, s, sum, arr, n)) return true;

    return false;
}
//3.It'll return the no. of sequence whoose sum(element) == sum (return 1 and 0, add all the fx calls)
int countSS(int i, int s, int sum, int arr[], int n){
    //Base cases
    if(s > sum) return 0;   //strictly if array contains positives only
    if(i == n){
        //condn satisfied
        if(s == sum){
            return 1;
        }
        //condn not satisfies
        return 0;
    }
    s += arr[i];
    int l = countSS(i+1, s, sum, arr, n);

    s -= arr[i];
    
    //not picked
    int r = countSS(i+1, s, sum, arr, n);

    return l+r;
}
int main(){
    int arr[] = {1, 2, 1};
    int n=3, i=0;
    int sum = 2;
    vector<int> ds;
    printSS(i, ds, 0, sum, arr, n);
    printSS1(i, ds, 0, sum, arr, n);
    int s=0;    //current Sum
    cout<<"No.of Subsequences = "<<countSS(i, s, sum, arr, n);

return 0;
}