// read and print student data and print name of student with highest marks
#include <iostream>
using namespace std;
class student{
    private: 
        int rollno;
        float marks;
        char name[10];
    public: 
        void input(){
               cout<< "enter rollno, marks, name";
                cin>> rollno >> marks >> name;}
                float marksret(){
                    return marks;
                }

void display(){
    cout<< name << "has max marks=  "<<marks;

}
};
int main(){
    student s[50];
 int n, loc=0;
 float marks=0;
 cout<<"enter the number of students: \n";
 cin>>n;
 for (int i=0; i<n;i++)
 {
     s[i].input();
 }
 for (int i=0;i<n; i++)
 {
     if( s[i].marksret()>marks){
         marks= s[i].marksret();
         loc=i;
     }
 }
s[loc].display();
return 0;
}