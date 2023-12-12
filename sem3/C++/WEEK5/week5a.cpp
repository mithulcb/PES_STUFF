#include<iostream>
using namespace std;

class A
{
    private: int l,b;
    public: void area(int ll,int bb);
};

void A::area(int ll,int bb)
{
    int ar;
    l=ll;
    b=bb;
    ar=l*b;
    cout<<"Area Of Rectangle Is:"<<ar<<endl;
}

int main()
{
    int l,b;
    A obj;
    cout<<"Enter Length:";
    cin>>l;
    cout<<"Enter Breadth:";
    cin>>b;
    obj.area(l,b);
    return 0;
}