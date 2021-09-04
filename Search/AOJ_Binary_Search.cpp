#include <bits/stdc++.h>
using namespace std;

vector<int> S;

// bool is_ok(int med, int n) {
//     return S[med] >= n;
// }

// bool binary_search(int n) {
//     int ok = S.size();
//     int ng = -1;
//     while (abs(ok-ng) > 1) {
//         int med = (ok + ng) / 2;
//         if (is_ok(med, n)) ok = med;
//         else ng = med;
//     }
//     if (ok != S.size()){
//         if (S[ok] == n) return true;
//     }
//     return false;
// }


int main() {
    int N; cin >> N;
    S.resize(N);
    for (int i=0; i<N; i++) cin >> S[i];
    int Q; cin >> Q;
    vector<int> T(Q); for (int i=0; i<Q; i++) cin >> T[i];
    int ans = 0;
    for (auto t : T) {
        if (binary_search(S.begin(), S.end(), t)) ans += 1;
    }
    cout << ans << endl;
}