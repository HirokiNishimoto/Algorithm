#include <bits/stdc++.h>
using namespace std;

#define INF 1000000;

int main() {
    // 例 1: 2 つの整数 a, b を入力し、a と b の最大公約数と最小公倍数を出力する
    int a, b;
    cin >> a >> b;
    int gcd = __gcd(a, b);
    cout << gcd << endl;
    cout << max(a,b)/gcd*min(a,b) << endl;
}