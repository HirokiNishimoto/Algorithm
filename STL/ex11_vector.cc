#include <bits/stdc++.h>
using namespace std;

#define INF 1000000;

int main() {
    // 例 1: a に色々な操作を行う（x1 = 105, x2 = 2, x3 = 146 となります）
    vector<int> v;
    v.push_back(121);
    v.push_back(105);
    v.push_back(193);
    int x1 = v[1];
    v.pop_back();
    int x2 = v.size();
    v.push_back(146);
    int x3 = v[2];
    cout << x1 << " " << x2 << " " << x3 << endl;
    return 0;

}