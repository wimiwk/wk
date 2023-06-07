#include <iostream>
#include <fstream>
using namespace std;
class Student {
public:
    int id;
    string name;
    int cpp_score;
    int math_score;
    int eng_score;
    int total_score;
    void calculate_total_score() {
        total_score = cpp_score + math_score + eng_score;
    }
};
int main() {
    Student students[100];
    // 读取学生的成绩并计算总成绩
    ifstream fin("score.dat",ios::binary);    
    int in_i=0;
    while(in_i!=100)
    {
        int id;
        string name;
        int cpp_score;
        int math_score;
        int eng_score;
        int total_score;
        fin>>id;
	    fin>>name;
        fin>>cpp_score;
        fin>>math_score;
        fin>>eng_score;
        students[in_i].id=id;
	    students[in_i].name=name;
        students[in_i].cpp_score=cpp_score;
        students[in_i].math_score=math_score;
        students[in_i].eng_score=eng_score;
        students[in_i].total_score=cpp_score+math_score+eng_score;
        in_i++;
    }
    fin.close();
    // 将数据写入二进制文件
    ofstream outfile("binary_score.dat", ios::binary);
    in_i=0;
    while(in_i!=100)
    {
        outfile<<students[in_i].id<<" "<<students[in_i].name<<" "<< students[in_i].cpp_score<< " "<<students[in_i].math_score<<" "<< students[in_i].eng_score<<" "<<students[in_i].total_score<<endl;
        in_i++;
    }
    string me="0123 魏侃 100 100 100 300";
    outfile.write(&me[0], sizeof(me));
    outfile.close();
    // 从二进制文件中读取数据并打印出来
    ifstream fin2("binary_score.dat", ios::binary);
    in_i=0;
    Student students2[101];
    while(in_i!=101)
    {
        int id;
        string name;
        int cpp_score;
        int math_score;
        int eng_score;
        int total_score;
        fin2>>id;
	    fin2>>name;
        fin2>>cpp_score;
        fin2>>math_score;
        fin2>>eng_score;
        fin2>>total_score;
        students2[in_i].id=id;
	    students2[in_i].name=name;
        students2[in_i].cpp_score=cpp_score;
        students2[in_i].math_score=math_score;
        students2[in_i].eng_score=eng_score;
        students2[in_i].total_score=total_score;
        in_i++;
    }
    fin.close();
    for (int i = 0; i < 101; i++) {
        cout << "学生: " << i+1 << endl;
        cout << "ID: " << students2[i].id << endl;
        cout << "姓名: " << students2[i].name << endl;
        cout << "C++成绩: " << students2[i].cpp_score << endl;
        cout << "数学成绩: " << students2[i].math_score << endl;
        cout << "英语成绩: " << students2[i].eng_score << endl;
        cout << "总成绩: " << students2[i].total_score << endl;
        cout << endl;
    }
    return 0;
}