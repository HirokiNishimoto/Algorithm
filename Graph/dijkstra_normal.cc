#include <bits/stdc++.h>
using namespace std;

// 入力として想定する頂点数の上限
static const int MAX = 100;.
// 整数型で桁あふれしない程度の大きい整数
static const int INF = (1<<21);
// 訪問したか否かの印
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

// 頂点数
int n;
// 隣接行列
vector<vector<int> > M(MAX, vector<int>(MAX, INF));

void dijkstra() 
{
    // 未訪問の頂点で、０頂点からの距離が最小の頂点
    int minv;

    // 頂点０からの距離
    vector<int> d(MAX);
    // 訪問の印
    vector<int> color(MAX);

    // 初期化
    for(int i=0; i < n; i++)
    {
        d[i] = INF;
        color[i] = WHITE;        
    }
    d[0] = 0;
    color[0] = GRAY;

    while(1)
    {
        minv = INF;
        int u = -1;
        for(int i=0; i<n; i++)
        {
            if (minv > d[i] && color[i] != BLACK)
            {
                u = i;
                minv = d[i];
            }
        }
        if(u==-1) break; // すべての頂点を訪れたら終了
        // 訪問した頂点に印をつける
        color[u] = BLACK;
        for(int v=0; v < n; v++)
        {
            // 動的計画法のよる配列の更新
            if(color[v] != BLACK && M[u][v] != INF)
            {
                if(d[v]>d[u]+M[u][v])
                {
                    d[v] = d[u] + M[u][v];
                    color[v] = GRAY;
                }
            }
        }
    }

    // 結果の出力
    for(int  i=0; i<n; i++)
    {
        cout << i << " " << (d[i] == INF ? -1 : d[i]) << endl;
    }
}

int main() 
{
    cin >> n;
    int k, c, u, v;
    for(int i=0; i< n; i++)
    {
        cin >> u >> k;
        for(int j=0; j < k; j++)
        {
            cin >> v >> c;
            M[u][v] = c;
        }
    }
    dijkstra();
    return 0;
}