#include <bits/stdc++.h>
using namespace std;
class student
{
    public:
    int roll;
    int id;
    double gpa;
    student(int roll, int id, double gpa)
    {
        this->roll = roll;
        this->id = id;
        this->gpa = gpa;
    }
};
student fun()
{
    student sobuj(212,15212,3.13);
    return sobuj;
}
int main() {
    
    student skz = fun();
    cout << skz.roll << endl << skz.id << endl << skz.gpa << endl;
    return 0;
}