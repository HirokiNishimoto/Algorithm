#include <bits/stdc++.h>
using namespace std;

#define INF 1000000;

int main() {
    // 例 1: 103, 168, 103 の中で最も大きい値を出力する : 168 が出力される
    cout << max({103, 168, 103}) << endl;

    // 例 2: {c[1], c[2], ..., c[N]} の最小値を出力する方法 1つ目
    int N;
    cin >> N;
    int c[N], minx=INF;
    for (int i=0; i<N; i++) {
        // cin >> *(c+i);
        cin >> c[i];
        minx = min(minx, c[i]);
    }
    cout << minx << endl;

    // 例 2: {c[1], c[2], ..., c[N]} の最小値を出力する方法 1つ目
    cout << *min_element(c, c+N) << endl;
}