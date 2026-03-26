#include <bits/stdc++.h>
using namespace std;
void fun(int x,int n)
{
    long long s=0;
    for (int i=2;i<=n;i+=2){
        s+=pow(x,i);
    }
    cout << s << endl;
    return ;
}
int main() {
    int x,n;
    cin >> x >> n;
    fun (x,n);
    return 0;
}