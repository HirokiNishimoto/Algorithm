#include <bits/stdc++.h>
using namespace std;

#define INF 1000000;

int main(){
    // 例 1: N 人の成績と名前を入力して、成績の大きい順にソートする
    int N;
    cin >> N;
    vector<pair<int, string>> V(N);
    int g;
    string n;
    for (int i=0; i<N; i++) {
        cin >> g >> n;
        V[i] = make_pair(g, n);
    }
    sort(V.begin(), V.end(), greater<pair<int, string>>());
    for (auto v : V) {
        cout << v.first << " " << v.second << endl;
    }
}