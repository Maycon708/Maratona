#include <bits/stdc++.h>
 
#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
 
using namespace std;
 
typedef pair <int, int> ii;
typedef long long int ll;

#define N 200020

vector<int> adj[N];
int a[N], ans[N];
set<int> vis[N];

void dfs( int u, int p, int op, int t ){
	if( vis[u].count(t) || t == 1 ) return;
	vis[u].insert(t);
	ans[u] = max( ans[u], __gcd( t, a[u] ) );
	if( op ) ans[u] = max( ans[u], t );
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i];
		if( v == p ) continue;
		dfs( v, u, op, __gcd( t, a[u] ) );
		if( op ) dfs( v, u, 0, t );
	}
}

int main(){
	int n, u, v;
	while( scanf("%d", &n ) != EOF ){
		rep( i, 1, n+1 ) scanf("%d", &a[i] ), adj[i].clear(), ans[i] = 1, vis[i].clear();
		rep( i, 1, n ){
			scanf("%d%d", &u, &v );
			adj[u].pb(v);
			adj[v].pb(u);
		} 
		dfs( 1, -1, 1, 0 );
		rep( i, 1, n+1 ) printf("%d%s", ans[i], i == n ? "\n" : " " );
	}
}
