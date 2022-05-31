//c++ program to create class which implements simple interest and compound interest
#include<iostream>
#include<math.h>
using namespace std;
class xyz{
    float p,r,t,n;
    public:
        xyz(float a=0, float b=0, float c=0, float d=0){
            p=a;
            r=b;
            t=c;
            n=d;
        }
    float si(){
        float s(p*r*t/100);
        return s;
    }
    float total_amount(){
        return p+si();
    }
    float ci(){
        float res= p*pow(1+r/n,n*t);
        return res;
    }
    ~xyz(){

    }

};
int main(){
    xyz t(5000, 0.05,10, 12);
    int c;
    cout<<" enter \n 1 for S.I\n 2 for C.I\n";
    cin>>c;
    if (c==1){
        cout<<t.si();
    }
    else{
        cout<<"wrong input!";

    }
    return 0;
}