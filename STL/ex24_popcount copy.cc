#include <bits/stdc++.h>
using namespace std;

int main() {
  // 例 1: x を 2 進数表記したときに、1 であるビットの個数を出力する。
  long long N, sum=0;
  cin >> N;
  cout << __builtin_popcount(N) << endl;
  bitset<2000> b(N);
  for (int i=0; i<2000; i++) sum += b[i];
  cout << sum << endl;
}