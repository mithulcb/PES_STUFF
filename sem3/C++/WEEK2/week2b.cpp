#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cout<<"Enter Value For A:";
    cin>>a;
    cout<<"Enter Value For B:";
    cin>>b;
    int * ptrA, *ptrB;
    ptrA=&a;
    ptrB=&b;
    cout<<"Printing using POINTERS\n";
    cout<<"Value for a is"<<endl;
    cout<<*ptrA<<endl;
    cout<<"Value for b is"<<endl;
    cout<<*ptrB<<endl;
    cout<<"Printing using VARIABLE\n";
    cout<<"Value for a is"<<endl;
    cout<<a<<endl;
    cout<<"Value for b is"<<endl;
    cout<<b<<endl;

    return 0;
}
