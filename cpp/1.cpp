#include <iostream>
#include <algorithm>
using namespace std;
class atm
{
private:
	int id[10]={1,2,3,4,5,6,7,8,9,10};
	int mon[10]={23,33,55,22,43,32,54,63,23,43};
	int num;
public:
	atm(int ide);
	~atm();
	void show();
	void cq(int a);
};
atm::atm(int ide)
{
	for (int i = 0; i < 10; i++)
		{
			if (ide==id[i])
			{
				num=i;
			}
		}
}
atm::~atm()
{
}
void atm::show(){
	cout<<"金额："<<mon[num]<<endl;
}
void atm::cq(int a){
	mon[num]+=a;
}
int main()
{ 
	int ide;
	cin>>ide;
    atm a(ide);
	for (;;)
	{
		string b;
		cin>>b;
		if (b=="exit")
		{
			break;
		}
		else if (b=="deposit")
		{
			int m;
			cin>>m;
			a.cq(m);
		}
		else if (b=="withdraw")
		{
			int n;
			cin>>n;
			a.cq(-1*n);
		}	
	}
	a.show();
	return 0;
}