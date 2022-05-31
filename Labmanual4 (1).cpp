//c++ program using structure to read details of student and find out max marks and print students marks in descending order
#include <iostream>
using namespace std;
struct student {
    int rollno;
    float marks;
    char name[10];

};
int main(){
    student s[50];
    int n, loc=0;
    float marks1=0;
    cout<<" enter the number of students:\n";
    cin>>n;
    cout<< "enter the rollno, name, marks :\n";
    for (int i=0; i<n; i++){
        cin>> s[i].rollno>>s[i].name>>s[i].marks;
    }
    for (int i=0; i<n; i++){
        if (marks1<s[i].marks){
            loc=i;
            marks1=s[i].marks;
        }
    }
    cout<<"the name of student with max marks is: "<<s[loc].name<<" = "<<s[loc].marks<<endl;
    cout<< "marks of students in descending order: "<<endl;
    for(int i=0;i<n;i++){
        cout<<s[loc].name<<" = "<<s[loc].marks<<endl;
        loc--;
    }
    return 0;
}