#include <iostream>
using namespace std;

template <typename T>
class Complex {
private:
    T real, imag;
public:
    Complex(T r = 0, T i = 0): real(r), imag(i) {}
    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }
    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }
    Complex operator*(const Complex& c) const {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }
    Complex operator/(const Complex& c) const {
        T denominator = c.real * c.real + c.imag * c.imag;
        return Complex((real * c.real + imag * c.imag) / denominator, (imag * c.real - real * c.imag) / denominator);
    }
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real << "+" << c.imag << "i";
        return os;
    }
    friend istream& operator>>(istream& is, Complex& c) {
        is >> c.real >> c.imag;
        return is;
    }
};

int main() {
    Complex<double> c1, c2, c3;
    cout << "c1: " << endl;
    cin >> c1;
    cout << "c2: " << endl;
    cin >> c2;
    cout << "c1=" << c1 << endl;
    cout << "c2=" << c2 << endl;
    c3 = c1 + c2;
    cout << "c1+c2=" << c3 << endl;
    c3 = c1 - c2;
    cout << "c1-c2=" << c3 << endl;
    c3 = c1 * c2;
    cout << "c1*c2=" << c3 << endl;
    c3 = c1 / c2;
    cout << "c1/c2=" << c3 << endl;
    return 0;
}