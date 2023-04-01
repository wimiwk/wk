#include <iostream>
using namespace std;
class juz
{
private:
    int m,n,jz[8][8];
public:
    juz();
    juz(int a,int b);
    ~juz();
    void into();
    friend void ch(juz *,juz *);
};
void ch(juz *a,juz *b);