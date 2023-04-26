#include <iostream>
#include <string>
#include <cmath>
using namespace std;
class point
{
protected:
    double x,y;
public:
    point(double x_,double y_){
        x=x_;
        y=y_;
    };
    ~point(){};
    double getX() const { 
        return x; 
    }
    double getY() const {
        return y; 
    }
    friend ostream& operator<<(ostream& os, const point& c) {
        os << "("<<c.x<<","<<c.y<<")";
        return os;
    }
};

class circle:public point
{
private:
    double r;
public:
    circle(double x = 0, double y = 0, double r = 0) : point(x, y), r(r) {}
    ~circle(){};
    double area() const { return M_PI * r * r; }
    friend int locate(const point& p, const circle& c){
        if ((p.getX()-c.getX())*(p.getX()-c.getX())+(p.getY()-c.getY())*(p.getY()-c.getY())<c.r*c.r) return -1;
        if ((p.getX()-c.getX())*(p.getX()-c.getX())+(p.getY()-c.getY())*(p.getY()-c.getY())==c.r*c.r) return 0;
        if ((p.getX()-c.getX())*(p.getX()-c.getX())+(p.getY()-c.getY())*(p.getY()-c.getY())>c.r*c.r) return 1;
    }
    friend bool operator<(const circle& c1, const circle& c2) {
        return c1.area() < c2.area();
    }
    friend bool operator<=(const circle& c1, const circle& c2) {
        return c1.area() <= c2.area();
    }
    friend bool operator==(const circle& c1, const circle& c2) {
        return c1.area() == c2.area();
    }
    friend bool operator!=(const circle& c1, const circle& c2) {
        return c1.area() != c2.area();
    }
    friend bool operator>(const circle& c1, const circle& c2) {
        return c1.area() > c2.area();
    }
    friend bool operator>=(const circle& c1, const circle& c2) {
        return c1.area() >= c2.area();
    }
};


int main( )
{
circle c1(3,2,4),c2(4,5,5); //c2 应该大于 c1
point p1(1,1),p2(3,-2),p3(7,3); //分别位于 c1 内、上、外
cout<<"圆 c1: "<<c1;
cout<<"点 p1: "<<p1;
cout<<"点 p1 在圆 c1 之"<<((locate(p1, c1)>0)?"外":((locate(p1, c1)<0)?" 内":"上"))<<endl;
cout<<"点 p2: "<<p2;
cout<<"点 p2 在圆 c1 之"<<((locate(p2, c1)>0)?"外":((locate(p2, c1)<0)?" 内":"上"))<<endl;
cout<<"点 p3: "<<p3;
cout<<"点 p3 在圆 c1 之"<<((locate(p3, c1)>0)?"外":((locate(p3, c1)<0)?" 内":"上"))<<endl;
cout<<endl;
cout<<"圆 c1: "<<c1;
if(c1>c2) cout<<"大于"<<endl;
if(c1<c2) cout<<"小于"<<endl;
if(c1>=c2) cout<<"大于等于"<<endl;
if(c1<=c2) cout<<"小于等于"<<endl;
if(c1==c2) cout<<"等于"<<endl;
if(c1!=c2) cout<<"不等于"<<endl;
cout<<"圆 c2: "<<c1;
cout<<endl;
return 0;
}