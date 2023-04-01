#include "college.h"
person::person()
{
}
person::~person()
{
}
void person::display(){

}

collegestu::collegestu():person::person()
{
    name="赵方婧";
    id=19971113;
    major="医学";
    score=100;
}
collegestu::~collegestu()
{
}
void collegestu::display(){
    cout<<"name:"<<name<<endl;
    cout<<"id:"<<id<<endl;
    cout<<"major:"<<major<<endl;
    cout<<"score:"<<score<<endl;
}