#include<iostream>
using namespace std;

void name1(string , int );

int main()
{
    int l;
    string name;
    cout<<"Enter name:";
    cin>>name;
    l=name.size();
    cout<<"Hello ";
    name1(name,l);
}

void name1(string name , int len)
{
    int i=0;
   for(i=0;i<=len;i++)
    {
        cout<<name[i];       
    }
    
}
