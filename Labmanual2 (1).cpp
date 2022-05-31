// read and print student data
#include <iostream>
using namespace std;
class student{
    private: 
        int rollno;
        float marks;
        char name[20];
    public: 
        void input(){
            cin>>rollno>>marks>> name;
}
void display(){
    cout<<rollno<<" "<< name<< " "<<marks;

}
};
int main(){
    student s;
    cout<< "enter rollno, marks, name"<<endl;
s.input();
s.display();
return 0;
}