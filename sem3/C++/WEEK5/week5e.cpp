#include <iostream>
using namespace std;
 
class C
{
public:
    int a, b;
    //default constructor
    C()
    {
        a = 10;
        b = 20;
    }
    //parameterized constructor
    C(int a1,int b1)
    {
        a=a1;
        b=b1;
        cout<<"Constructor Is Called\n";
    }
    //copy constructor
    C(const C &p)
    {
        a=p.a;
        b=p.b;
    }
    //destructor
    ~C()
    {
        cout<<"Destructor Is Called\n";
    }
    //copy assignment operator
    C& operator=(const C &c)
    {
        cout<<"Assignment Operator Called"<<endl;
        return *this;
    } 
};

int main()
{
    C obj,obj1(20,30),obj2;
    obj2=obj;

    cout<<"Default Constructor:"<<endl;
    cout<<"a:"<<obj.a<<endl;
    cout<<"b:"<<obj.b<<endl;
    cout<<endl;

    cout<<"Parameterized Constructor:"<<endl;
    cout<<"a:"<<obj1.a<<endl;
    cout<<"b:"<<obj1.b<<endl;
    cout<<endl;

    cout<<"Copy Constructor:"<<endl;
    cout<<"a:"<<obj2.a<<endl;
    cout<<"b:"<<obj2.b<<endl;
    cout<<endl;

    return 0;;
}