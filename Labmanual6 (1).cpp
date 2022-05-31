// C++ program to add three complex numbers
#include <iostream>
using namespace std;
class Complex
{
public:
    int real;
    int imag;
    void setvalue()
    {
        cin >> real;
        cin >> imag;
    }
    void display()
    {
        cout << real << "+" << imag << "i" << endl;
    }
    void sum(Complex c1, Complex c2, Complex c3)
    {
        real = c1.real + c2.real + c3.real;
        imag = c1.imag + c2.imag + c3.imag;
    }
};
int main()
{
    Complex c1, c2, c3,c4;
    cout << "Enter real and imaginary part of first complex number" << endl;
    c1.setvalue();
    cout << "Enter real and imaginary part of second complex number" << endl;
    c2.setvalue();
    cout << "Enter real and imaginary part of third  complex number" << endl;
    c3.setvalue();
    cout << "Sum of three complex numbers is" << endl;
    c4.sum(c1, c2, c3);
    c4.display();
    return 0;
}