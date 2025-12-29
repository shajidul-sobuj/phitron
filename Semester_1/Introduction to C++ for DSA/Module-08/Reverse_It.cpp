#include <bits/stdc++.h>
using namespace std;
class Student
{
    public:
    string nm;
    int cls;
    char s;
    int id;
};
int main() {
    int n;
    cin >> n;
    Student a[n];
    for (int i=0;i<n;i++) {
        cin >> a[i].nm >> a[i].cls >> a[i].s >> a[i].id;
    }
    // revarse(a->s,a->s+n);
    for (int i=0,j=n-1;i<n;i++,j--) {
        cout << a[i].nm << " " << a[i].cls << " " << a[j].s << " " << a[i].id << endl;
    }

    return 0;
}