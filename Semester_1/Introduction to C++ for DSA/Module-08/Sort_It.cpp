#include <bits/stdc++.h>
using namespace std;
class Student
{
    public:
    string nm;
    int cls;
    char s;
    int id;
    int math_marks;
    int eng_marks;

};
int main() {
    int n;
    cin >> n;
    Student a[n];
    for (int i=0;i<n;i++) {
        cin >> a[i].nm >> a[i].cls >> a[i].s >> a[i].id >> a[i].math_marks >> a[i].eng_marks;
    }
    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            if ((a[i].math_marks+a[i].eng_marks)<(a[j].math_marks+a[j].eng_marks)) {
                Student temp;
                temp = a[i];
                a[i]=a[j];
                a[j]=temp;
            }else if ((a[i].math_marks+a[i].eng_marks)==(a[j].math_marks+a[j].eng_marks) && a[i].id>a[j].id) {
                Student temp;
                temp = a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    for (int i=0,j=n-1;i<n;i++,j--) {
        cout << a[i].nm << " " << a[i].cls << " " << a[i].s << " " << a[i].id << " " << a[i].math_marks << " " << a[i].eng_marks << endl;
    }

    return 0;
}


//Next N lines will contain nm, cls, s, id, math_marks and eng_marks respectively.