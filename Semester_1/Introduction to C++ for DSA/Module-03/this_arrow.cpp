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
int main() {
    
    student sobuj(212,15212,3.13);
    cout << sobuj.roll << " " << sobuj.id << " " << sobuj.gpa << endl;
    return 0;
}