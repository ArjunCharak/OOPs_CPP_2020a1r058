// area of the circle
#include<iostream>
using namespace std;
class a {
private: 
    float r, area;
public: 
    void input()
    {
        cout<< "enter the radius of the circle"<<endl;
        cin>>r;
    }
    void display()
    {
        cout<<"area of the circle: "<<endl;
        cout<< 3.14*r*r<<endl;

    }
};
int main()
{
    a s;
    s.input();
    s.display();
    return 0;

}