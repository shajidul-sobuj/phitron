#include <bits/stdc++.h>
using namespace std;
int main() {

    // typ1-1

        vector <int> v = {1,2,3,4,5};
        v.erase(v.begin()+2);                    // ekta value delete korte 
        for (int x : v) {
            cout << x << " ";
        }



    // type-2;

        vector <int> v = {1,2,3,4,5};
        v.erase(v.begin()+1,v.end()-1);         // onek gula value delete korte 
        for (int x : v) {
            cout << x << " ";
        }



    return 0;
}