//c++ program using constructor and destructor
#include<iostream>
using namespace std;
class construct{
    public:
        int a,b;
            construct(){
                a=10;
                b=20;

            }
            ~construct()
            {

            }

};
int main(){
    construct c;
    cout<<"a: "<<c.a<<endl;
    cout<<"b: "<<c.b<<endl;
    return 0;
}