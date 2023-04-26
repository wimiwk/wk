#include <iostream>
using namespace std;
class Cbuilding {
protected:
    int floors;
    int rooms;
    double area;
public:
    Cbuilding(int f, int r, double a) : floors(f), rooms(r), area(a) {}
};
class CHousing : public Cbuilding {
private:
    int bedrooms;
    int bathrooms;
public:
    CHousing(int f, int r, double a, int b, int bath) : Cbuilding(f, r, a), bedrooms(b), bathrooms(bath) {}
    void printData() {
        cout << "CH1" << endl;
        cout << "楼房层数：" << floors << endl;
        cout << "房间数：" << rooms << endl;
        cout << "总面积：" << area << endl;
        cout << "卧室数：" << bedrooms << endl;
        cout << "浴室数：" << bathrooms << endl;
    }
};
class COfficBuilding : public Cbuilding {
private:
    int fireExtinguishers;
    int telephones;
public:
    COfficBuilding(int f, int r, double a, int fire, int phone) : Cbuilding(f, r, a), fireExtinguishers(fire), telephones(phone) {}
    void printData() {
        cout << "CH2" << endl;
        cout << "楼房层数：" << floors << endl;
        cout << "房间数：" << rooms << endl;
        cout << "总面积：" << area << endl;
        cout << "存储灭火器数：" << fireExtinguishers << endl;
        cout << "电话数：" << telephones << endl;
    }
};
int main() {
    CHousing ch1(3, 10, 200.5, 4, 2);
    COfficBuilding ch2(5, 20, 500.0, 10, 5);
    ch1.printData();
    ch2.printData();
    return 0;
}
