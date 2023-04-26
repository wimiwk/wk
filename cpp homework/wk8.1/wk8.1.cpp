#include <iostream>
using namespace std;
class csolid {
protected:
    double s,v;
public:
    virtual double s_count() =0;
    virtual double v_count() =0;
};
class ccube : public csolid {
protected:
    double len_side;
public:
    ccube(double side){
        len_side=side; 
    }
    double s_count() {
        s=len_side*len_side*6;
        cout<<"正方体面积："<<s<<endl;
        return s;
    }
    double v_count(){
        v=len_side*len_side*len_side;
        cout<<"正方体体积："<<v<<endl;
        return v;
    } 
};
class cball : public csolid {
protected:
    double r;
public:
    cball(double round){
        r=round;
    }
    double s_count(){
        s=4*r*r*3.14;
        cout<<"球面积："<<s<<endl;
        return s;
    }
    double v_count(){
        v=4/3*3.14*r*r*r;
        cout<<"球体积："<<v<<endl;
        return v;
    } 
};
class ccylinder : public csolid {
protected:
    double r,h;
public:
    ccylinder(double round,double high){
        r=round;
        h=high;
    }
    double s_count(){
        s=3.14*r*r*2+2*3.14*r*h;
        cout<<"圆柱面积："<<s<<endl;
        return s;
    }
    double v_count(){
        v=3.14*r*r*h;
        cout<<"圆柱体积："<<v<<endl;
        return v;
    } 
};
int main(){
    csolid *p;
    double ball_r,cube_side,cylinder_r,cylinder_h;
    cout<<"输入正方体边长：";
    cin>>cube_side;
    cout<<"输入球半径：";
    cin>>ball_r;
    cout<<"输入圆柱半径：";
    cin>>cylinder_r;
    cout<<"输入圆柱高：";
    cin>>cylinder_h;
    cball ball(ball_r);
    ccube cube(cube_side);
    ccylinder cylinder(cylinder_r,cylinder_h);
    p=&cube;
    p->s_count();
    p->v_count();
    p=&ball;
    p->s_count();
    p->v_count();
    p=&cylinder;
    p->s_count();
    p->v_count();
    return 0;
}