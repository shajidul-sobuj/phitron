#include <bits/stdc++.h>
using namespace std;
class student
{
    public:
    char name[1001];
    int roll;
    double gpa;
};
int main() {
    student a,b;

    cin.getline(a.name,1001);
    cin >> a.roll >> a.gpa ;
    cin.ignore();
    cin.getline(b.name,1001);
    cin >> b.roll >> b.gpa ;
    cout << "Name: " << a.name << endl << "Roll: " << a.roll << endl << "GPA: " << a.gpa << endl;
    cout << endl;
    cout << "Name: " << b.name << endl << "Roll: " << b.roll << endl << "GPA: " << b.gpa << endl;


    return 0;
}