#include <iostream>
using namespace std;

class Imagin{
	public:

	int x,y;

	Imagin(int nx, int ny){

	x=nx;y=ny;}
};

int main(){

	int nu1,nu2;
	cout << "first number \n";
	cout<< "Enter the real part:";
	cin>> nu1;
	cout<< "Enterthe imaginary part:";
	cin>> nu2;
	Imagin number1(nu1,nu2);
	cout << "second number \n";
    int nu3,nu4;
	cout<< "Enter the real part:";
	cin>> nu3;
	cout<< "Enterthe imaginary part:";
	cin>> nu4;
	
	Imagin number2(nu3,nu4);

	int real;

    real = number1.x +number2.x;

    int imagin;

    imagin = number2.x + number1.y;

    cout << "the sum of the real parts is "<< real << "\n";
    cout << "the sum of the imaginary parts is "<<imagin;

    return 0;
}