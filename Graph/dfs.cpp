#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

//typedef
//------------------------------------------
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<PII> VP;
typedef long long ll;

//REPEAT
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//container util
//------------------------------------------
#define pb push_back
#define paired make_pair
#define ALL(a) (a).begin(),(a).end()
#define PRINT(V) for (auto v : (V)) cout << v << " "
#define SORT(V) sort((V).begin(),(V).end())
#define RSORT(V) sort((V).rbegin(), (V).rend())

//constant
//------------------------------------------
const int MOD = 1000000007;
const int INF = 1061109567;
const double EPS = 1e-10;
const double PI  = acos(-1.0);

VI D, F;
vector<bool> seen;
Graph G;

void dfs(Graph& G, int v, int& time) {
    if (not seen[v]) {
        D[v] = time++;
        seen[v] = true;
        for (int c : G[v]) {
            dfs(G, c, time);
        }
        F[v] = time++;
    }
}

int main() {
    int N; cin >> N;
    G.resize(N);
    REP(i, N) {
        int _, E;
        cin >> _ >> E;
        REP(j, E) {
            int e;
            cin >> e;
            G[i].push_back(e-1);
        }
    }
    D.resize(N);
    F.resize(N);
    seen.assign(N, false);
    int time = 1;
    REP(i, N) dfs(G, i, time);
    REP(i, N) {
        cout << i+1 << " " << D[i] << " " << F[i] << endl;
    }
