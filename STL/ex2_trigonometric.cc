#include <bits/stdc++.h>
using namespace std;

int main() {
    // 例 2: 三角関数の利用例。x を角度で入力し、sin(x),cos(x),tan(x) の値を出力します。
    double theta;
    cout << "theta:";
    cin >> theta;

    double rad = theta / 180 * M_PI;

    cout << "cos(theta): " << cos(rad) << endl;
    cout << "sin(theta): " << sin(rad) << endl;
    cout << "tan(theta): " << tan(rad) << endl;
}