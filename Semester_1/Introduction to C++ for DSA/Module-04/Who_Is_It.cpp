#include <bits/stdc++.h>
using namespace std;
class student 
{
    public: 
    int id;
    char name[1001];
    char x;
    int roll;

};
int main() {
    int t;
    cin >> t;
    for (int i=1;i<=t;i++) {
        student a,b,c;
        cin >> a.id >> a.name >> a.x >> a.roll;
        cin >> b.id >> b.name >> b.x >> b.roll;
        cin >> c.id >> c.name >> c.x >> c.roll;

        if (a.roll>=b.roll && a.roll >= c.roll) {
            if (a.roll>b.roll && a.roll > c.roll) {
                cout << a.id << " " << a.name << " " << a.x << " " << a.roll << endl;
            }else if (a.roll==b.roll || a.roll == c.roll) {
                cout << a.id << " " << a.name << " " << a.x << " " << a.roll << endl;
            }
        }else if (b.roll>=a.roll && b.roll >= c.roll) {
            if (b.roll>a.roll && b.roll > c.roll) {
                cout << b.id << " " << b.name << " " << b.x << " " << b.roll << endl;
            }else if (a.roll==b.roll) {
                cout << a.id << " " << a.name << " " << a.x << " " << a.roll << endl;
            }else if (b.roll == c.roll) {
                cout << b.id << " " << b.name << " " << b.x << " " << b.roll << endl;
            }
        }else if (c.roll>=a.roll && c.roll >= a.roll) {
            if (c.roll > a.roll && c.roll > a.roll) {
                cout << c.id << " " << c.name << " " << c.x << " " << c.roll << endl;
            }else if (a.roll==c.roll) {
                cout << a.id << " " << a.name << " " << a.x << " " << a.roll << endl;
            }else if (b.roll == c.roll) {
                cout << b.id << " " << b.name << " " << b.x << " " << b.roll << endl;
            }
        }

    }

    return 0;
}