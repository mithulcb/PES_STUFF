#include<iostream>
using namespace std;

class Student
{
    private:
    int no;
    char name[20];

    public:
    void get();
    void display();
};

void Student::get()
{
    cout<<"Enter Name:";
    cin>>name;
    cout<<"Enter ID:";
    cin>>no;
}

void Student::display()
{
    cout<<"Name:"<<name<<endl;
    cout<<"ID:"<<no<<endl;
}

int main()
{
    Student s,*sp;
    sp=&s;
    sp->get();
    sp->display();
    return 0;
}