#include "juz.h"
juz::juz()
{
    this->m=0;
    this->n=0;
}
juz::juz(int a,int b){
    this->m=a;
    n=b;
}
juz::~juz()
{
}
void juz::into(){
	for (int i = 0; i < m; i++)
	{
		for (int ii = 0; ii < n; ii++)
		{
			cin>>jz[i][ii];
		}
	}
}
void ch(juz *a,juz *b){
	int re[a->m][b->n];
	int x=0;
	for (int i = 0; i < a->m; i++)
	{
		for (int ii = 0; ii < b->n; ii++)
		{
			int dl=0;
			for (int iii = 0; iii < a->n; iii++)
			{
				dl+=a->jz[i][iii]*b->jz[iii][ii];
			}
			cout<<dl<<" ";
		}
		cout<<endl;
	}
	
}