#include <iostream>
#include <algorithm>
using namespace std;
class savingaccount
{
private:
	int id;
	double balance=0;
    double rate;
    int lastdate;
    double accumulation=0;
    double accumulate(int date);
public:
	savingaccount(int date,int id,double rate);
    void deposit(int date,double amount);
    void withdraw(int date,double amount);
    void settle(int date);
    void show();
    int getid(){return id;}
    double getbalance(){return balance;}
    double getrate(){return rate;}
};
savingaccount::savingaccount(int date,int uid,double urate)
{
    lastdate=date;
    id=uid;
    rate=urate;
}
void savingaccount::deposit(int date,double amount){
    accumulation+=balance*(date-lastdate);
    balance+=amount;
    lastdate=date;
}
void savingaccount::withdraw(int date,double amount){
    accumulation+=balance*(date-lastdate);
    balance-=amount;
    lastdate=date;
};
void savingaccount::settle(int date=90){
    accumulation+=balance*(date-lastdate);
    balance=accumulation*(1.00+rate)/date;
};
void savingaccount::show(){
    cout<<"账号："<<id<<"的"<<"余额："<<balance<<endl;
}
int main() 
{ 
	savingaccount s0(0,1,1.5/100.0),s1(0,2,1.5/100.0);
    s0.deposit(5,5000);
    s0.deposit(45,5500);
    s1.deposit(25,10000);
    s1.withdraw(60,4000);
    s1.settle();
    s0.settle();
    s1.show();
    s0.show();
	return 0;
}