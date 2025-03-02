#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<int> v)
{
    for(auto it: v)
        cout << it << " ";
    cout << "\n";
}

int main(){
    vector<int> v;
    v.push_back(63);    //Insert element 63.
    v.push_back(12);    //Insert element 12.
    v.push_back(42);    //Insert element 42.
    v.push_back(33);    //Insert element 33.
    v.push_back(56);    //Insert element 56.
    v.push_back(98);    //Insert element 98.
    v.emplace_back(100);    //Insert element 98. Faster than v.push_back()

    //Now the vector(v) has 6 elements in it
    int n = v.size();
    cout << "The size of the vector is " << n << "\n";
    
    //The elements present in the vector are printed using the print_vector function
    print_vector(v);

    v.pop_back();               //remove the last element (by making size-1, but popped element will be there)
    print_vector(v);
    // v.erase(v.begin()+3);       //delete element from specified position
    v.erase(v.end()-2);       //delete element from specified position
    print_vector(v);

    sort(v.begin(), v.end());
    print_vector(v);
    cout<<v.front()<<endl;
    cout<<v.back()<<endl;
    cout<<*v.begin()<<endl;
    cout<<*v.end()<<endl;
    v.clear();                  //it clear all the elements, not capacity(memory allocated)
    
    cout << "\nAll the elements of the vector are removed using the pop_back function.\n";
    return 0;
}