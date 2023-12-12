#include<iostream>
using namespace std;
void ADDITION(int a,int b);
void SUBTRACTION(int a,int b);
void MULTIPLICATION(int a,int b);
void DIVISION(int a,int b);
int main()
{
    int a,b,c;
    cout<<"Enter Any Two Numbers To Perform Operation:";
    cin>>a>>b;
    cout<<"Calculator:"<<endl;
    cout<<"1. ADDITION"<<endl;
    cout<<"2. SUBTRACTION"<<endl;
    cout<<"3. MULTIPLICATION"<<endl;
    cout<<"4. DIVISION"<<endl;
    cout<<"Enter Your Choice:"<<endl;
    cin>>c;
    switch(c)
    {
        case 1:
        ADDITION(a,b);
        break;
        case 2:
        SUBTRACTION(a,b);
        break;
        case 3:
        MULTIPLICATION(a,b);
        break;
        case 4:
        DIVISION(a,b);
        break;
        default:
        cout<<"Enter Valid Choice"<<endl;
    }
    return 0;
}
void ADDITION(int a,int b)
{
    cout<<"Addition of "<<a<<" & "<<b<<" is "<<(a+b)<<endl;
}
void SUBTRACTION(int a,int b)
{
    cout<<"Subtraction of "<<a<<" & "<<b<<" is "<<(a-b)<<endl;
}
void MULTIPLICATION(int a,int b)
{
    cout<<"Multiplication of "<<a<<" & "<<b<<" is "<<(a*b)<<endl;
}
void DIVISION(int a,int b)
{
    cout<<"Division of "<<a<<" & "<<b<<" is "<<(int)(a/b)<<endl;
}