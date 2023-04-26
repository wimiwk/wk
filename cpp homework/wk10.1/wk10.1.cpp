#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
using namespace std;
class String
{
public:
    String(const char* p_=""){
        len = strlen(p_);
        p = new char[len + 1];
        strcpy(p, p_);
    }
    ~String(){
    }
    void print_string(){
        /*for (int i = 0; i <= len; i++)
        {
            cout<<p[i];
        }*/
        cout<<p<<endl;
        cout<<len<<endl;
    }
    String operator+(const String& other) const {
        String result;
        result.len = len + other.len;
        result.p = new char[result.len + 1];
        strcpy(result.p, p);
        strcat(result.p, other.p);
        return result;
    }
    String operator-(const String& c) const {
        String result;
        string s = p;
        string s_ =c.p;
        int lPos = s.find_first_not_of(' ');
        int rPos = s_.find_last_not_of(' ');
        result.len = len-lPos+1+rPos;
        result.p = new char[result.len + 1];
        strcpy(result.p, s.substr(0,rPos+1).c_str());
        strcat(result.p, s_.substr(lPos,c.len-lPos+1).c_str());
        return result;
    }
//需要的成员函数（若需要的话，声明友元函数）
private:
    char *p; //指向存储的字符串
    int len; //记录字符串的长度
};
int main( )
{
    char str_1[90],str_2[90];
    cin.getline(str_1,999);
    cin.getline(str_2,999);
    char *str__1=str_1,*str__2=str_2;
    String str1(str__1),str2(str__2);
    String str3=str1-str2;
    String str4=str1+str2;
    str3.print_string();
    str4.print_string();
    return 0;
}