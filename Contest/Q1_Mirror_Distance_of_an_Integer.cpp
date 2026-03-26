class Solution {
public:
    int mirrorDistance(string n) {
        string y = n;
        reverse(y.begin(), y.end());
        int a = stoi(n);
        int b = stoi(y);
        return abs(a - b);
    }
};