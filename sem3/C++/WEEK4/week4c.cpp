#include <iostream>
#include <string>
using namespace std;
  
void show_static()
{
    static int a=0;
    cout<<a<<" ";
    a++;
}

void show_non_static()
{ 
    int b=0;
    cout<<b<<" ";
    b++;
}
  
int main()
{
    for (int i=0;i<=3;i++)
    {
        cout<<"Static:";
        show_static();
        cout<<endl;
    }
    for(int i=0;i<=3;i++)
    {
        cout<<"Non-Static:";
        show_non_static();
        cout<<endl;
    }
    return 0;
}