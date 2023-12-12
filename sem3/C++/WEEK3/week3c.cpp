#include<iostream>
using namespace std;

int main()
{
    int n,a[100];
    int i,*max,*p;
    max=&a[0];
    cout<<"Number Of Values:";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"Enter Value:";
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        p=&a[i];
        if(*p>=*max)
            max=p;
    }
    cout<<"Max Value :"<<*max<<endl;
    return 0;
}