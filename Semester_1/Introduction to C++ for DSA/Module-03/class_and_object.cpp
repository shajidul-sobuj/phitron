#include <bits/stdc++.h>
using namespace std;
class student
{
    public:
    char name[1001];
    int roll;
    double gpa;
};
int main()
{
    student sobuj;
    char temp [1001] = "Shajidul Islam Sobuj";
    strcpy(sobuj.name,temp);
    sobuj.roll = 20;
    sobuj.gpa = 4.5;
    cout << "Name: " << sobuj.name << endl << "Roll: " << sobuj.roll << endl << "GPA: "  << sobuj.gpa << endl;
    return 0;
}