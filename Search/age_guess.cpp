#include <bits/stdc++.h>
using namespace std;



int main() {
    int age; cin >> age;
    int mid;
    int is_ok = 120; // age以上
    int is_ng = -1;  // age未満
    while (abs(is_ok-is_ng) > 1) {
        mid = (is_ok + is_ng) / 2;
        if (mid >= age) is_ok = mid;
        else is_ng =mid;
    }
    cout << is_ok << endl;
}