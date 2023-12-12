#include<iostream>
using namespace std;

int main()
{
    int* a=NULL,n;
    cout<<"Enter Number Of Inputs:";
    cin>>n;
    a=new int[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Element:";
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
        cout<<a[i]<<"\n";
    delete[] a;
    return 0;
}