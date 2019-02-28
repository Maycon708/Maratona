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

vector<int> adj[1000];
int h[1000], best[1000];

void dfs( int u, int p ){
	int a = 0, b = 0;
	best[u] = 0;
	for( auto v : adj[u] ){
		if( v == p ) continue;
		dfs(v, u);
		best[u] = max( best[u], best[v] );
		if( h[v] > a ){
			b = a;
			a = h[v];
		}
		else b = max( b, h[v] );
	}
	h[u] = a+1;
	best[u] = max( best[u], a+b );
}

int main(){
	int n, a[1000], b[1000];
	scanf("%d", &n );
	rep( i, 0, n-1 ){
		scanf("%d%d", &a[i], &b[i] );
		adj[a[i]].pb(b[i]);
		adj[b[i]].pb(a[i]);
	}
	int ans = 0;
	rep( i, 0, n-1 ){
		dfs( a[i], b[i] );
		dfs( b[i], a[i] );
		ans = max( ans, best[a[i]] * best[b[i]] );
	}
	
	cout << ans << "\n";
}
