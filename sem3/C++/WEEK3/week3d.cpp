#include <iostream>
using namespace std;

int main()
{
    char a[]="A string";
    char *b;
    b=a;
    cout<<"Letter on index 0 is "<< *b << " and printing " << *(b+3)<<" using pointer"<<endl;
    b=b+2;
    cout<<"Currently pointer is at "<< *b << " and printing "<<*(b+2)<<" and "<<*(b+5)<<" using pointer "<<endl;

}