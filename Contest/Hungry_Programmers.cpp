#include <iostream>
using namespace std;

int main() {
    double n, x, m, y;
    cin >> n >> x >> m >> y;

    double fc = y / m;
    double pc = (x <= fc) ? (n / x) : (n / fc);

    cout << (int)pc << endl;
}
