#include <iostream> 
using namespace std;
class dwu
{
private:
    char a[3];
public:
    dwu(char c,char v,char b);
    ~dwu();
    friend void cn(dwu *,dwu *);
};
void cn(dwu *j,dwu *y);