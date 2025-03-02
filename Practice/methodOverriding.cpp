#include <iostream>
using namespace std;
class Parent{
    protected:
    int l, b;
    public:
    void in(){
        l=5, b=2;
    }
    virtual void area(){    //if virtual keyword is not used, then method will not override and parent class method will be called again
        cout<<"Area of rectangle : "<<l*b<<endl;
    }
};
class Traingle : public Parent{
    public:
    void area(){
        in();
        cout<<"Area of traingle : "<<(float)l*b/2<<endl;
    }
};
int main(){
    Parent *ptr;
    ptr = new Parent();
    ptr->in();
    ptr->area();
    ptr = new Traingle();
    ptr->area();

return 0;
}