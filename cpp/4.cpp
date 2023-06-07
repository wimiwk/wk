#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
#include <iomanip>
using namespace std;
int len[7][7];
class city
{
public:
    city(int num_=0,string name_="0"){
        num=num_;
        name=name_;
    }
    ~city(){}
private:
    int num;
    string name;
};
void ask_len(){
        int n=6;
        for(int k = 1 ; k <= n ; k ++)
        {
        for(int i = 1 ; i <= n ; i ++)
        {
            for(int j = 1 ; j <= n ; j ++)
            {
                if(len[i][j] > len[i][k] + len[k][j]) len[i][j] = len[i][k] + len[k][j];
            }
        }
        } 
    }
int main( )
{
    city bj(1,"北京");
    city sh(2,"上海");
    city gz(3,"广州");
    city cd(4,"成都");
    city wh(5,"武汉");
    city xa(6,"西安");
    for (int i = 1; i <=6; i++)
    {
        for (int j = 1; j <=6; j++)
        {
            len[i][j]=10000;
        }
    }
    for (int i = 1; i <= 6; i++)
    {
        len[i][i]=0;
    }
    len[1][2]=1000;
    len[2][1]=1000;
    len[1][6]=1000;
    len[6][1]=1000;
    len[2][5]=750;
    len[5][2]=750;
    len[4][3]=1400;
    len[3][4]=1400;
    len[4][5]=800;
    len[5][4]=800;
    len[4][6]=600;
    len[6][4]=600;
    len[5][6]=1000;
    len[6][5]=1000;
    ask_len();
    for (int i = 1; i <=6; i++)
    {
        for (int j = 1; j <=6; j++)
        {
            cout<<len[i][j]<<"  ";
        }
        cout<<endl;
    }
    
    

    

    return 0;
}