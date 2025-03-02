#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n=3;
    int mat[3][3]={{1,2,3},{4,5,6},{7,8,9}};

    // 90deg clk=trens+change col 
    cout<<"\n original:"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<mat[i][j];
        }
        cout<<endl;
    }

    vector<vector<int>>temp(n,vector<int>(n));
    // transform
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            temp[j][i]=mat[i][j];
            
            // swap(mat[i][j],mat[j][i]);

        }
    }
    cout<<"after transform:"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<temp[i][j];
        }
        cout<<endl;
    }

    // now reverse by row
    for(int i=0;i<3;i++){
        reverse(temp[i].begin(),temp[i].end());
    }

 cout<<"after 90deg clh:"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<temp[i][j];
        }
        cout<<endl;
    }

    return 0;
}