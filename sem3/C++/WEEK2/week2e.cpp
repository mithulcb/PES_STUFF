#include <iostream>
using namespace std;
int comp(int,int);
int main()
{
int num1,num2;
	cout << " Input the first integer: ";
	cin>> num1;
	cout << " Input the second integer: ";
	cin>> num2;	
    cout<<"The larger number is:";
    cout<<comp(num1,num2)<<endl;
    return 0;
}

int comp(int a,int b)
{
    if(a>b){
        return a;
    }else if(b>a){
        return b;
    }else{
        return 0;
    }
}