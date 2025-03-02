#include <bits\stdc++.h>
using namespace std;

bool isvalid(string car_n)
{
    if (car_n.length() >= 6 and car_n.length() <= 8)
        return true;
    return false;
}

int main()
{
    vector<string> car = {"MH04CC2", "MH04C2820", "MH04BB3223", "MH04CC2113", "MH04CC2878", "MH04BBB", "MH04CC2888", "Mh04CC1313", "MH04CCC222", "Mh04C1201", "MH04CC555", "Mh04C6565", "MHO4A7"};
    int op;
    cout << "enter 1.park or 2.search:";
    cin >> op;
    string cn;
    cout << "enter car number :";
    cin >> cn;
    if (op == 1)
    {
        if (isvalid(cn))
            car.push_back(cn);
        else
            cout << "invalid";
    }
    else if (op == 2)
    {
        for (int i = 0; i < car.size(); i++)
        {
            if (car[i] == cn)
            {
                cout << "at pos:" << i + 1;
                break;
            }
        }
    }
    else
    {
        cout << "invalid";
    }

    return 0;
}