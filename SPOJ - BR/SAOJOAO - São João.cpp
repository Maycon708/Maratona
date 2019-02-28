#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 200000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

vector<int> adj[N];
int dist[2][N], d;

void dfs( int u, int p, int t ){
	if( dist[t][u] > dist[t][d] ) d = u;
	for( auto v : adj[u] ){
		if( v == p ) continue;
		dist[t][v] = dist[t][u]+1;
		dfs(v, u, t);
	}
}

int main(){
	int n, u, v, q, m;
	while( scanf("%d", &n ) != EOF ){
		rep( i, 0, n+1 ) adj[i].clear();
		rep( i, 1, n ){
			scanf("%d%d", &u, &v );
			adj[u].pb(v);
			adj[v].pb(u);
		}
		dfs( 1, -1, 0 );
		dist[0][d] = 0;
		dfs( d, -1, 0 );
		dist[1][d] = 0;
		dfs( d, -1, 1 );
		scanf("%d", &q );
		while( q-- ){
			scanf("%d%d", &u, &m );
			int maior = max( dist[0][u], dist[1][u] );
			printf("%d\n", min( n, 1 + min(m, maior) + max( 0, (m-maior)/2 )));
		}
		
	}
}

