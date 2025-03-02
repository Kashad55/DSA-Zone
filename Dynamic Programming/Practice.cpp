#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct student{
    string name;
    int roll; 
    int fees;
};
class School{
    public:         //Mandatory, else not possible to access the data member
    string name;
    int roll;
    int fees;
};
void arraySize(int *arr, int &n){
    if(arr[0] > 1000) return;       //we choose 100 bcoz after array ends, it'll show garbage value which is generally >10000
    n++;
    arraySize(arr+1, n);
    // for(int i=0; arr[i] < 1000; i++){
    //     n++;
    // }
}
int power(int a, int b){
    if(b==0) return 1;
    if(b==1) return a;

    int ans = power(a, b/2);
    if(b%2 == 0){
        return ans*ans;
    }
    else{
        return a*ans*ans;
    }
}
int bs(int *arr, int s, int e, int key){
    if(s>e) return -1;

    int mid = s+(e-s)/2;
    if(arr[mid] == key) return mid;

    if(arr[mid] > key) return bs(arr, s, mid-1, key);
    else return bs(arr, mid+1, e, key); 
}
void selSort(int *arr, int n, int i){
    if(i==n) return;

    for(int j = i+1; j<n; j++){
        if(arr[i] > arr[j]){
            swap(arr[i], arr[j]);
        }
    }
    selSort(arr, n, i+1);
}
void printStack(stack<int> st){
    //base case 
    if(st.empty()) return;

    int num = st.top();
    st.pop();
    cout<<num<<endl;

    printStack(st);

    st.push(num);
}
void deleteMiddle(stack<int> &st, int count, int size){
    if(count == size/2){
        st.pop();
        return;
    }

    int num = st.top();
    st.pop();

    deleteMiddle(st, count+1, size);

    st.push(num);
}
void deleteMid(stack<int> &st){
    int size = st.size();
    int count = 0;
    deleteMiddle(st,count, size);
}
vector<int> printSpiral(vector<vector<int>> mat){
    vector<int> ans;
    int row = mat.size();
    int col = mat[0].size();

    int count = 0;
    int total = row*col;

    int sR=0, sC=0;
    int eR=row-1, eC=col-1;
    while(count < total){
        //starting row
        for(int i=sC; i<=eC && count < total; i++){
            ans.push_back(mat[sR][i]);
            count++;
        }
        sR++;

        //ending col
        for(int i=sR; i<=eR && count < total; i++){
            ans.push_back(mat[i][eC]);
            count++;
        }
        eC--;

        //ending row
        for(int i=eC; i>=sC && count < total; i--){
            ans.push_back(mat[eR][i]);
            count++;
        }
        eR--;

        //starting col
        for(int i=eR; i>=sR && count < total; i--){
            ans.push_back(mat[i][sC]);
            count++;
        }
        sC++;
    }
    return ans;
}
vector<int> printWave(vector<vector<int>> mat){
    vector<int> ans;
    int row = mat.size();
    int col = mat[0].size();
    for(int i=0; i<col; i++){
        if(i & 1){  //odd index(bottom -> top)
            for(int j = row-1; j>=0; j--){
                ans.push_back(mat[j][i]);
            }
        }
        else{       //even index(top -> bottom)
            for(int j=0; j<row; j++){
                ans.push_back(mat[j][i]);
            }
        }
    }
    return ans;
}
int main(){
    // vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}}; 
    // // vector<int> arr = printSpiral(mat);
    // vector<int> arr = printWave(mat);
    // for(auto it : arr) cout<<it<<" ";

    // stack<int> st;
    // st.push(5);
    // st.push(1);
    // st.push(7);
    // st.push(0);
    // st.push(3);
    // printStack(st);
    // deleteMid(st);
    // printStack(st);

    // int arr[] = {1,2,3,7,4,5,0};
    // selSort(arr,7, 0);
    // for(auto i : arr) cout<<i<<" ";

    // cout<<bs(arr,0,5,3);

    // cout<<power(2,10);

    // int arr[] = {1,2,3,4,5,10};
    // // cout<<arr[7]<<endl;
    // int n=0;
    // arraySize(arr, n);
    // cout<<n;


    // struct student s;
    // s.name = "Kashad";
    // s.roll = 43;
    // s.fees = 20000;
    // s = {"Piya", 53, 21000};
    // cout<<s.name<<" "<<s.roll<<" "<<s.fees;

    // struct student s[5];
    // cout<<"Enter name, roll, fees : "<<endl;
    // for(int i=0; i<3; i++){
    //     cout<<"Enter data for student "<<i+1<<" : ";
    //     cin>>s[i].name>>s[i].roll>>s[i].fees;
    // }
    // for(int i=0; i<3; i++){
    //     cout<<"Data of student "<<i+1<<" : ";
    //     cout<<s[i].name<<" "<<s[i].roll<<" "<<s[i].fees;
    //     cout<<endl;
    // }
    // School s[5];
    // cout<<"Enter name, roll, fees"<<endl;
    // for(int i=0; i<3; i++){
    //     cout<<"Enter data for student "<<i+1<<" : ";
    //     cin>>s[i].name>>s[i].roll>>s[i].fees;
    // }
    // for(int i=0; i<3; i++){
    //     cout<<"Data of student "<<i+1<<" : ";
    //     cout<<s[i].name<<" "<<s[i].roll<<" "<<s[i].fees;
    //     cout<<endl;
    // }


return 0;
}