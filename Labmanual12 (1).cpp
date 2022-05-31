#include<iostream>
using namespace std;
class sample1
{
    protected:float x,y;
    public: 
    float z;
    void input(){
        cout<<"enter the value of x and y: "<<endl;
        cin>>x>>y;
    }
    void display(){
        cout<<z;
    }
    void add(){
        z=x+y;
    }
void diff() {
    if (x>y)
    {
        z=x-y;
    }
    else
    {
         z=y-x;
    }
}
};
int main(){
    sample1 s1,s2;
    cout<<"for addition"<<endl;
    s1.input();
    s1.add();
    s1.display();
    cout<<endl<<"for subtraction"<<endl;
    s2.input();
    s2.diff();
    s2.display();
    return 0;
}