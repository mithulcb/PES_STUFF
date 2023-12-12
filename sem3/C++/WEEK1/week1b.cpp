#include <iostream>  
using namespace std;  
class animal {  
   public:  
      int age;      
      string name;      
};  
int main() {  
    animal s1;   
    s1.age = 201;    
    s1.name = "Tortoise";   
    cout<<s1.age<<endl;  
    cout<<s1.name<<endl;  
    return 0;  
}
  

/*
int main()
{
    int r=201;
    string n="tortoise";
    cout<<"Name"<<n<<endl;
    cout<<"Age:"<<r<<endl;
    return 0;
}*/

