#include <bits/stdc++.h>
using namespace std;

int main() {
    // 例 1: 入力した 2 つの文字列を連結して、最初の 10 文字を出力します。
    string s1, s2;
    cin >> s1 >> s2;
    string c = s1 + s2;
    if (c.size() <= 10) {
        cout << c << endl;
    }
    else {
        cout << c.substr(0, 10) << endl;
    }

    // 例 2: 入力した文字列 s の偶数文字目を 'z' に変えて出力します。
    string s;
    cin >> s;
    for (int i=0; i < s.size(); ++i) {
        cout << (i % 2 == 0 ? *"z" : s[i]);
    }
    cout << endl;
}