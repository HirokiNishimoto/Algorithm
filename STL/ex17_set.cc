#include <bits/stdc++.h>
using namespace std;

#define INF 1000000;

int main(){
    // 例 1: set に対して色々な操作を行う（1 個目は "End"、2 個目は "46" と出力される）
    set<int> S;
    S.insert(1);
    S.insert(3);
    S.insert(2);
    S.insert(3);
    S.insert(7);
    S.insert(4);
    auto itr1 = S.lower_bound(10);
    cout << *itr1 << endl;
    if (itr1 == S.end()) cout << "End" << endl;
    auto itr2 = S.lower_bound(3);
    cout << *itr2 << endl;
    auto itr3 = S.lower_bound(5);
    cout << *itr3 << endl;
    cout << S.size() << endl;
    S.erase(7);
    cout << S.size() << endl;
    S.erase(S.begin());
    cout << S.size() << endl;

     // 例 2: a[1],a[2],...,a[N] を小さい順に出力する（同じ要素が複数ある場合 1 回だけ出力する）
    set<int> b; int N;
    cin >> N;
        int a[N];
    for (int i = 0; i <= N-1; i++) cin >> a[i];
    for (int i = 0; i <= N-1; i++) b.insert(a[i]);
    auto i = b.begin();
    while (i != b.end()) {
        cout << *i << endl;
        ++i;
    }
    cout << a[N-1] << " " << a[N] << endl;
}