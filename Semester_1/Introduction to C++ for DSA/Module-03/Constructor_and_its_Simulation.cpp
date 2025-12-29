#include <bits/stdc++.h>
using namespace std;
class student
{
    public:
    int roll;
    int id;
    double gpa;
    student(int r, int d, double g)
    {
        roll = r;
        id = d;
        gpa = g;
    }
};
int main() {
    
    student sobuj(212,15212,3.13);
    cout << sobuj.roll << " " << sobuj.id << " " << sobuj.gpa << endl;
    return 0;
}