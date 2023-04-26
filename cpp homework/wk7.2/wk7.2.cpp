#include <iostream>
#include <string>
using namespace std;
class Person {
protected:
    string name;
    int age;
    string gender;
    string address;
    string phone;
public:
    virtual void input(string name_,int age_,string gender_,string address_,string phone_){
        name=name_;
        age=age_;
        gender=gender_;
        address=address_;
        phone=phone_;
    }
};

class Teacher : public Person {
protected:
    string title;
public:
    virtual void input(string name_,int age_,string gender_,string address_,string phone_,string title_) {
        name=name_;
        age=age_;
        gender=gender_;
        address=address_;
        phone=phone_;
        title=title_;
    }
    void display() {
        cout << "姓名:" << name << endl;
        cout << "年龄:" << age << endl;
        cout << "性别:" << gender << endl;
        cout << "职称:" << title << endl;
        cout << "地址:" << address << endl;
        cout << "电话:" << phone << endl;
    }
};
class Cadre : public Person {
protected:
    string post;
public:
    virtual void input(string name_,int age_,string gender_,string address_,string phone_,string post_) {
        post=post_;
    }
    void display() {
        cout << "姓名:" << name << endl;
        cout << "年龄:" << age << endl;
        cout << "性别:" << gender << endl;
        cout << "职务:" << post << endl;
        cout << "地址:" << address << endl;
        cout << "电话:" << phone << endl;
    }
};
class Teacher_Cadre : public Teacher, public Cadre {
protected:
    double wages;
public:
    virtual void input(string name_,int age_,string gender_,string address_,string phone_,string title_,string post_,double wages_) {
        Teacher::name=name_;
        Teacher::age=age_;
        Teacher::gender=gender_;
        Teacher::address=address_;
        Teacher::phone=phone_;
        title=title_;
        post=post_;
        wages=wages_;
    }
    void show() {
        cout << "姓名:" << Teacher::name << endl;
        cout << "年龄:" << Teacher::age << endl;
        cout << "性别:" << Teacher::gender << endl;
        cout << "职称:" << title << endl;
        cout << "地址:" << Teacher::address << endl;
        cout << "电话:" << Teacher::phone << endl;
        cout << "职务:" << post << endl;
        cout << "工资:" << wages << endl;
    }
};
int main(){
    Teacher_Cadre TC;
    string name;
    int age,wages;
    string gender;
    string address;
    string phone,title,post;
    cout << "请输入姓名：";
    getline(cin, name);
    cout << "请输入年龄：";
    cin >> age;
    while (age < 0) {
        cout << "年龄不能低于0，请重新输入：";
        cin >> age;
    }
    cout << "请输入性别：";
    cin >> gender;
    while (gender != "man" && gender != "woman") {
        cout << "性别只能是man或woman，请重新输入：";
        cin >> gender;
    }
    cin.ignore();
    cout << "请输入职称和职务：";
    getline(cin, title,'.');
    getline(cin, post);
    cin.ignore();
    cout << "请输入地址：";
    getline(cin, address);
    cout << "请输入电话：";
    getline(cin, phone);
    cout << "请输入工资：";
    cin >> wages;
    while (wages < 0) {
        cout << "工资不能低于0，请重新输入：";
        cin >> wages;
    }
    TC.input(name,age,gender,address,phone,title,post,wages);
    TC.show();
    return 0;
}