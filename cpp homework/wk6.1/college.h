#include <iostream>
using namespace std;
class person
{ 
public:
    int id;
    string name;
    person();
    ~person();
    void display();
};
class collegestu:virtual public person
{
public:
    double score;
    string major;
    collegestu();
    ~collegestu();
    void display();
};