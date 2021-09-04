#include <bits/stdc++.h>
using namespace std;

int main() {
    // 例 1: a[1], a[2], ..., a[N] を受け取る。その後、Q 個の質問を受け取る。
    // 各質問は (l, r, x) の組から成り、a[l], a[l+1], ..., a[r] の中で x が存在しない場合 -1
    // そうでない場合、存在する位置（ポインタではない）を出力する。
    int N; cin >> N;
    int a[N]; for (int i=0; i<N; i++) cin >> a[i];
    int Q; cin >> Q;
    int l, r, x;
    for (int i=0; i<Q; i++) {
        cin >> l >> r >> x;
        auto pos = find(a+l, a+r+1, x) - a;
        if (pos != r) cout << pos << endl;
        else cout << -1 << endl;
    }
}