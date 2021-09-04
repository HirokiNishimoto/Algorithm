#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    int a[N];
    iota(a, a+N, 0);
    do {
        for (int i=0; i<N; i++) {
            cout << a[i] << (i == N-1 ? "\n" : " ");
        }
    } while (next_permutation(a, a+N));
}