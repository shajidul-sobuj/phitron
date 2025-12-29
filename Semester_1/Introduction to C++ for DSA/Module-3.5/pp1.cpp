#include <bits/stdc++.h>
using namespace std;
class Student
{
    public:
	char name[1001];
	int roll;
	char section;
	int math_marks;
	int cls;
    Student(char name[1001],int roll,char section,int math_marks,int cls)
        {
            this->name[1001]=name[1001];
            this->roll=roll;
            this->section=section;
            this->math_marks=math_marks;
            this->cls=cls;
        }
};
int main() {
    Student a(strcpy(a.name,"Sobuj"),212,'I',98,13);
    Student b(strcpy(b.name,"Sajid"),213,'I',96,13);
    Student c(strcpy(c.name,"Sobuj"),214,'I',97,13);
    // cout << a.name << " " << a.roll << " " << a.section << " " << a.math_marks << " " << a.cls;
    if (a.math_marks>b.math_marks && a.math_marks>c.math_marks) {
        cout << a.name << endl;
    }


    return 0;
}