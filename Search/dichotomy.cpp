#include <bits/stdc++.h>
using namespace std;


double f(double x) {
    return pow(x, 2) - 3;
}

double binary_search() {
    double is_ok = 2; // >= 0
    double is_ng = 0; // <  0

    double mid;
    while (abs(is_ok-is_ng) > 0.000000000001) {
        mid = (is_ok + is_ng) / 2;
        if (f(mid) >= 0) is_ok = mid;
        else is_ng = mid;
    }
    return is_ok;
}

int main() {
    cout << binary_search() << endl;
}