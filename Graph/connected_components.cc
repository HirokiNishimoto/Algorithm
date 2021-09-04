//------------------------------------------
// C++ templete 
//------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

//typedef
//------------------------------------------
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<PII> VP;

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
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

//math
//------------------------------------------
int QP(int a,int b){int ans=1;do{if(b&1)ans=1ll*ans*a%MOD;a=1ll*a*a%MOD;}while(b>>=1);return ans;}
int QP(int a,int b,int MOD){int ans=1;do{if(b&1)ans=1ll*ans*a%MOD;a=1ll*a*a%MOD;}while(b>>=1);return ans;}
int GCD(int a,int b){return b?GCD(b,a%b):a;}

//debug
//------------------------------------------
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

//grobal variable
//------------------------------------------

const int MAX = 100000;
const int NIL = -1;

int n;

vector<int> G[MAX];
int color[MAX];

void dfs(int r, int c)
{
    stack<int> S;
    S.push(r);
    color[r] = c;
    while(!S.empty())
    {
        int u = S.top(); S.pop();
        REP(i, G[u].size())
        {
            int v = G[u][i];
            if (color[v] == NIL ) 
            {
                color[v] = c;
                S.push(v);
            }
        }
    }
}

void assignColor() {
    int id = 1;
    REP(i, n) color[i] = NIL;
    REP(u, n)
    {
        if (color[u] == NIL) dfs(u, id++);
    }
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int s, t, m, q;
    cin >> n >> m;
    VI S[10000], T[10000];
    REP(i, m)
    {
        cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    
    assignColor();

    cin >> q;

    REP(i, q)
    {
        cin >> s >> t;
        if (color[i] == color[t])
        {
            cout << "yes" << endl;
        } 
        else
        {
            cout << "no" << endl;
        }
    }
  
    return 0;
}

