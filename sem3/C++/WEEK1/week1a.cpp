#include <iostream>
using namespace std;

int main()
{
    int p;
    float q;
    char r; 
    double d;   
    cout << "Enter the integer value::\n";
    cin >> p;    
    cout << "Enter the float value::\n";
    cin >> q;  
    cout << "Enter the double value::\n";
    cin >> d;    
    cout << "Enter the character value::\n";
    cin >> r;
    
    cout << "\nThe integer input is:\n" << p << "\n";
    cout << "\nThe float input is:\n" << q << "\n";
    cout << "\nThe double input is:\n" << d << "\n";
    cout << "\nThe string input is:\n" << r << "\n";
    
    return 0;
}