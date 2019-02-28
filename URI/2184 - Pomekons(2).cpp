#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define it(i, a)  for( typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

const int maxn = 100010, maxl = 20;

vector<int> E[maxn];
vector<int> W[maxn];
int prof[maxn];
int dist[maxn][maxl];
int pai[maxn][maxl];
int n, m;

void dfs( int v, int p, int depth, int d ){
    prof[v] = depth;
    dist[v][0] = d;
    pai[v][0] = p;
    for( int i = 1; i < maxl; i++ ){
        pai[v][i] = pai[ pai[v][i-1] ][i-1];
        dist[v][i] = max( dist[v][i-1], dist[pai[v][i-1]][i-1] );
    }
    for (int i = 0; i < E[v].size(); i++ ){
        int viz = E[v][i];
        if( viz == p ) continue;
        dfs( viz, v, depth+1, W[v][i] );
    }
}

void calc(){
    for( int i = 0; i < maxl; i++ ){
        pai[0][i] = 0; dist[0][i] = -INF;
    }
    for( int i = 0; i < E[0].size(); i++ ){
        dfs( E[0][i], 0, 1, W[0][i] );
    }
}

ii solve( int a, int b ){
    int pa = a, pb = b, resp = -INF, edges = prof[a] + prof[b];
    if( prof[pb] > prof[pa] ) swap( pa, pb );
	while( prof[pa] > prof[pb] ){
        int j = 0;
        for( int i = 0; i < maxl; i++ ){
            if( prof[pai[pa][i]] < prof[pb] ) break;
            j = i;
        }
        resp = max( resp, dist[pa][j] ); pa = pai[pa][j];
    }
    while( pa != pb ){
        int j = 0;
        for( int i = 0; i < maxl; i++ ){
            if( pai[pa][i] == pai[pb][i] ) break;
            j = i;
        }
        resp = max( resp, dist[pa][j] ); resp = max( resp, dist[pb][j] );
        pa = pai[pa][j]; pb = pai[pb][j];
    }
    edges -= 2*prof[pa];
    return ii( resp, edges+1 );
}

void init( int n ){
	rep( i, 0, n )
        E[i].clear(), W[i].clear();
}

int pd[5011][1011];
vector<ii> V;

int knapsack( int pos, int cap ){
	if( pos == V.size() ) return 0;
	if( pd[pos][cap] != -1 ) return pd[pos][cap];
	int ans = knapsack( pos+1, cap );
	if( cap >= V[pos].S ) ans = max( ans, knapsack( pos+1, cap - V[pos].S ) + V[pos].F );
	return pd[pos][cap] = ans;
}

int main(){
	
	int n, k, u, v, c, a, b, q;
	while( scanf("%d%d", &n, &k ) != EOF ){
		init( n ); V.clear();
		rep( i, 1, n ){
			scanf("%d%d%d", &u, &v, &c ); 
			u--, v--;
			E[u].pb(v), E[v].pb(u);
			W[u].pb(c), W[v].pb(c);
		}
		calc();
		scanf("%d", &q );
		rep( i, 0, q ){
			rep( j, 0, k+1 ) pd[i][j] = -1;
			scanf("%d%d", &a, &b );
			a--, b--;
			ii aux = solve( a, b );
			V.pb( aux );
		}
		int ans = knapsack( 0, k );
		if( !ans ) printf("-1\n");
		else printf("%d\n", ans );
	}
}
