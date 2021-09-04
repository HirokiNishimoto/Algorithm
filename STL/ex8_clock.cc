#include <bits/stdc++.h>
using namespace std;

#define INF 1000000;

int main() {
     // 例 1: 実行にかかる時間を計測する
    int ti = clock();
    for (int i = 1; i <= 100000; i++) {
        cout << i << endl;
    }
    cout << "実行時間: " << ((float)clock()-ti)/CLOCKS_PER_SEC << endl;
}