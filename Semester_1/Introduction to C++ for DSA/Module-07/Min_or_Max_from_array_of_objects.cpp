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
    Student mn,mx;
    mn.cgpa = INT_MAX;
    mx.cgpa = INT_MIN;
    for (int i=0;i<n;i++) {
        if (a[i].cgpa>mx.cgpa) {
            mx = a[i];
        }
        if (a[i].cgpa<mn.cgpa) {
            mn = a[i];
        }
    }
    cout << mx.name << " " << mx.id << " " << mx.cgpa << endl;
    cout << mn.name << " " << mn.id << " " << mn.cgpa << endl;


    return 0;
}