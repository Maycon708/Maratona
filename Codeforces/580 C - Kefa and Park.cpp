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
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

#define N 100010

int m, cat[N], cnt;
vector<int> adj[N];

void dfs( int u, int p, int c ){
	if( c > m ) return;
	if( adj[u].size() == 1 && u != 0 ) cnt++;
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i];
		if( v == p ) continue;
		dfs( v, u, cat[v] ? c+1 : 0 );
	}
}

int main(){
	int n, u, v;
	while( scanf("%d%d", &n, &m ) != EOF ){
		rep( i, 0, n ){
			adj[i].clear();
			scanf("%d", &cat[i] );
		}
		rep( i, 1, n ){
			scanf("%d%d", &u, &v );
			u--, v--;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		cnt = 0;
		dfs(0, -1, cat[0] );
		printf("%d\n", cnt );
	}
}


