#include<iostream>
using namespace std;
void call_ref(int &r,int &s,int &t);
void call_poi(int *p1,int *p2,int *p3);
void call_val(int a,int b,int c);
int main()
{
    int a,b,c;
    cout<<"Enter a:";
    cin>>a;
    cout<<"Enter b:";
    cin>>b;
    cout<<"Enter c:";
    cin>>c;
    cout<<"Before Swapping:";
    cout<<a<<"\t"<<b<<"\t"<<c<<endl;
    cout<<"After Swapping Using Call By Reference:";
    call_ref(a,b,c);
    cout<<"After Swapping Using Call By Pointer:";
    call_poi(&a,&b,&c);
    cout<<"After Swapping Using Call By Value:";
    call_val(a,b,c);
}
void call_val(int a,int b,int c)
{
    int temp;
    temp=a;
    a=b;
    b=c;
    c=temp;
    cout<<a<<",";
    cout<<b<<",";
    cout<<c<<endl;
}
void call_ref(int &r,int &s,int &t)
{
    int temp;
    temp=r;
    r=s;
    s=t;
    t=temp;
    cout<<"New values of a,b,c are:";
    cout<<r<<",";
    cout<<s<<",";
    cout<<t<<endl;
}
void call_poi(int *p1,int *p2,int *p3)
{
    int temp;
    temp=*p1;
    *p1=*p2;
    *p2=*p3;
    *p3=temp;
    cout<<"New values of a,b,c are:";
    cout<<*p1<<",";
    cout<<*p2<<",";
    cout<<*p3<<endl;
}