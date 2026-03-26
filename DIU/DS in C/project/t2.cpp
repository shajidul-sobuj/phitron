#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define endl '\n'

unordered_set<tuple<int, int, string, string>> st;

void n1()
{
    int temp;
    int hum;
    string da,ti;
    cout << "Date: ";
    cin >> da;
    cout << "Time: ";
    cin >> ti;
    cout << "Temperature: ";
    cin >> temp;
    cout << "Humiditi: ";
    cin >> hum;

    st.insert({temp,hum,da,ti});
}

void n2()
{
    cout << endl << endl << "Date   ||   Time   || Temperature  ||  Humidity\n";
    unordered_set<tuple<int, int, string, string>> pr = st;
    for (auto [a,b,c,d] : pr)
    {
        cout << c << "   ||   " << d << "   ||   " << a << "   ||   " << b << endl;
    }

    cout << endl << endl;
}


int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    while(1)
    {
        cout << "1. Input Waither Data\n";
        cout << "2. Show All Data\n";
        cout << "3. Edit any Data\n";
        cout << "0. Exit\n";
        cout << "Chose any option: \n";
        int n;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        else if (n == 1)
        {
            n1();
        }
        else if (n == 2)
        {
            n2();
        }
    }

    return 0;
}