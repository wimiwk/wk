#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
#include <iomanip>
using namespace std;
class Seller
{
public:
    static double sum,discount;
    static int n;
    static double average(Seller *seller,int n){
        int count=0;
        for (int i = 0; i < n; i++)
        {
            count+=seller[i].quantity;
            if (seller[i].quantity>10)
            {
                sum+=seller[i].quantity*1.00*seller[i].price*seller->discount*0.98;
            }
            else sum+=seller[i].quantity*1.00*seller[i].price*seller->discount;
        }
        return sum/count;
    }
    
    static void display(Seller *seller,int n){
        double result_av=average(seller,n);
        cout<< fixed << setprecision(2)<<sum<<endl;
        cout<< fixed << setprecision(2)<<result_av<<endl;
    }
    Seller(int num_=0,int quantity_=0,double price_=0.0){
        num=num_;
        quantity=quantity_;
        price=price_;
    }
    ~Seller(){}
    void cin_(int num_,int quantity_,double price_){
        num=num_;
        quantity=quantity_;
        price=price_;
    }
private:
    int num,quantity;
    double price;
};
double Seller::discount = 0.0;
double Seller::sum = 0.0; // 添加初始化
int main( )
{
    int n;
    cin>>n;
    Seller *seller = new Seller[n];
    for (int i = 0; i < n; i++)
    {
        int num,quantity;
        double price;
        cin>>num>>quantity>>price;
        seller[i].cin_(num,quantity,price);
    }
    cin>>seller->discount;
    seller->display(seller,n);
    delete[] seller;
    return 0;
}