#include <iostream>
using namespace std;
class counter
{
private:
    int co;
    int zh=0;
public:
    counter(int n);
    ~counter();
    void cl(int n);
};