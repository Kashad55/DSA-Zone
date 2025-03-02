#include <iostream>
#include<map>
using namespace std;
int main()
{
    cout << "\nWELCOME to CCD";
    cout << "\n enter menu";
    char M;
    cin >> M;
    cout << "\nEnter submenu(1-3):";
    int sm;
    cin >> sm;

    map<char,map<int,string>>mp;

    map<int,string>fs,ss,ts,bs;

    fs[1]="Esx";
    fs[2]="cap";
    fs[3]="lat";
    mp['C']=fs;

    ss[1]="plain";
    ss[2]="assa";
    ss[3]="ginger";
    ss[4]="car";
    ss[5]="lemaonm";
    ss[6]="gre";
    ss[7]="org";
    mp['T']=ss;

    ts[1]="hot";
    ts[2]="veg sorm";
    ts[3]="tom";
    ts[4]="spicy tom";
    mp['S']=ts;

    fs[1]="chot";
    fs[2]="badam";
    fs[3]="pista";
    mp['B']=bs;

    if(M=='T' or M=='C' or M=='B' or M=='S'){
        if(M=='C'){
            if(sm>3 or sm<=0){
                cout<<"invalid";
            }
            else cout<<"Enjoy ur"<<mp['C'][sm];
        }
        else if(M=='T'){
            if(sm>8 or sm<=0){
                cout<<"invalid";
            }
            else  cout<<"Enjoy ur"<<mp['T'][sm];
        }
        else if (M=='B'){
            if(sm>3 or sm<=0){
                cout<<"invalid";
            }
            else  cout<<"Enjoy ur"<<mp['B'][sm];
        }
        else{
            if(sm>4 or sm<=0){
                cout<<"invalid";
            }
            else  cout<<"Enjoy ur"<<mp['S'][sm];
        
        }
    }
    else{
        cout<<"invalis:";
    }


// app 2
    // switch (M)
    // {
    // case 'C':
    //     cout << "\nEnter submenu(1-3):";
    //     int sm;
    //     cin >> sm;
    //     switch (sm)
    //     {
    //     case 1:
    //         cout << "epresso coffe";
    //         break;
    //     case 2:
    //         cout << "cappussino coffee";
    //         break;
    //     case 3:
    //         cout << " latte coffe";
    //         break;
    //     }
    //     break;
    // case 'T':
    //     cout << "\nEnter submenu(1-8):";
    //     int smt;
    //     cin >> smt;
    //     switch (smt)
    //     {
    //     case 1:
    //         cout << "plain tea";
    //         break;
    //     case 2:
    //         cout << "assam tea";
    //         break;
    //     case 3:
    //         cout << " ginger tea";
    //         break;
    //     case 4:
    //         cout << " Cardamon tea";
    //         break;
    //     case 5:
    //         cout << " Masala tea";
    //         break;
    //     case 6:
    //         cout << " lemaon tea";
    //         break;
    //     case 7:
    //         cout << " green tea";
    //         break;
    //     case 8:
    //         cout << " Organic Darjeeling tea";
    //         break;
    //     }
    //     break;
    // case 'S':
    //     cout << "\nEnter submenu(1-4):";
    //     int sms;
    //     cin >> sms;
    //     switch (sms)
    //     {
    //     case 1:
    //         cout << "hote and sour soup";
    //         break;
    //     case 2:
    //         cout << "veg corn soup";
    //         break;
    //     case 3:
    //         cout << " tommato soup coffe";
    //         break;
    //     case 4:
    //         cout << "spicy tomato soup";
    //         break;
    //     }
    //     break;
    // case 'B':
    //     cout << "\nEnter submenu(1-3):";
    //     int smb;
    //     cin >> smb;
    //     switch (smb)
    //     {
    //     case 1:
    //         cout << "Hot Chocolate drink";
    //         break;
    //     case 2:
    //         cout << "badam drink";
    //         break;
    //     case 3:
    //         cout << " badam pista drink";
    //         break;
    //     }
    //     break;
    // }
    return 0;
}