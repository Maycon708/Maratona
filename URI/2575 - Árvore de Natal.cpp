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

typedef int ll;
typedef pair <ll, ll> ii;

#define N 1000100

vector<ll> cut[N], C;
vector< pair<ii, ll> > adj[N];
ll val[N];

void dfs( int u, int p = -1 ){
	val[u] = 0;
	cut[u].resize( adj[u].size(), 0 );
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i].F.F;
		int w = adj[u][i].F.S;
		if( p == v ) continue;
		dfs( v, u );
		if( val[v] + w <= 0 ) cut[u][i] = 1;
		else val[u] += val[v]+w;
	}
}

void dfs2( int u, int p = -1 ){
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i].F.F;
		if( p == v ) continue;
		if( cut[u][i] ) C.pb( adj[u][i].S );
		else dfs2( v, u );
	}
}

int main(){
	
	int n, id, u, v, w;
	while( scanf("%d", &n ) != EOF ){
		C.clear();
		rep( i, 0, n+1 ) adj[i].clear(), cut[i].clear();
		rep( i, 1, n ){
			scanf("%d%d%d%d", &id, &u, &v, &w );
			adj[u].pb( mk( ii( v, w ), id ));
			adj[v].pb( mk( ii( u, w ), id ));
		}
		dfs(0);
		dfs2(0);
		sort( all(C) );
		printf("%d %d\n", val[0], (ll)C.size() );
		rep( i, 0, C.size() ){
			printf("%d%s", C[i], (i+1 == C.size()) ? "\n" : " " );
		}
	}

}
