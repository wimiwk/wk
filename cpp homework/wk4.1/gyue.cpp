#include "gyue.h"
gyue::gyue()
{
    this->m=0;
    this->n=0;
}
gyue::gyue(int a,int b){
    this->m=a;
    n=b;
}
gyue::~gyue()
{
}
void gyue::gyresult(){
    int temp;
	temp=(m>n)?n:m;         //采用条件运算表达式求出两个数中的最小值
	while(temp>0)
	{
		if(m%temp==0&&n%temp==0)     //只要找到一个数能同时被a,b所整除，则中止循环
			break;
		temp--;                        //如不满足if条件则变量自减，直到能被a,b所整除
	}
	cout<<temp<<endl;
}
void gyue::gbresult(){
    int p,q,temp;
	p=(m>n)?m:n;                     //求两个数中的最大值
	q=(m>n)?n:m;                     //求两个数中的最小值
	temp=p;                        //最大值赋给p为变量自增作准备
	while(1)                        //利用循环语句来求满足条件的数值
	{
		if(p%q==0)
			break;                  //只要找到变量的和数能被a或b所整除，则中止循环
		p+=temp;                   //如果条件不满足则变量自身相加
	}
	cout<<p<<endl;
}