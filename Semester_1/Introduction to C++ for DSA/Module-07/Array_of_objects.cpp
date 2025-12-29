#include <bits/stdc++.h>
using namespace std;
class Student
{
    public:
    string name;
    int id;
    double cgpa;
};
int main() {
    int n;
    cin >> n;
    Student a[n];
    for (int i=0;i<n;i++) {
        cin >> a[i].name >> a[i].id >> a[i].cgpa;
    }
    for (int i=0;i<n;i++) {
        cout << a[i].name << " " << a[i].id << " " <<  a[i].cgpa << endl;
    }

    return 0;
}