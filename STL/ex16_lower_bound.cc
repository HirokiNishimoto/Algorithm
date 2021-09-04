#include <bits/stdc++.h>
using namespace std;

#define INF 1000000;

int main()
{
    // 例 1: a[i] < x となるような i が何個あるのかを O(log N) で計算する
    int N;
    cin >> N;
    int c[N];
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }
    sort(c, c+N, less<int>());
    int x;cin >> x;
    cout << lower_bound(c, c + N, x) - c << endl;
    cout << *lower_bound(c, c + N, 100) << endl;
    cout << *lower_bound(c, c+N, *max_element(c, c+N)+1) << endl;
}