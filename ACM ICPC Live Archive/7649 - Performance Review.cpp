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

#define N 100100

vector<int> adj[N];
int n , p[N], r[N], root, t[N];
ll ans[N], bit[N];

void update( int x, int v ){
	for( ; x < N; x += x&-x ) bit[x] += v;
}

ll query( int x ){
	ll ans = 0;
	for( ; x > 0; x -= x&-x ) ans += bit[x];
	return ans;
}

void dfs( int u ){
	ll tmp = query( r[u]-1 );
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i];
		dfs(v);
	}
	ans[u] = query( r[u]-1 ) - tmp;
	update( r[u], t[u] );
}

int main(){
	while( scanf("%d", &n ) != EOF ){
		for( int i = 1; i <  N; i++ ) adj[i].clear(), ans[i] = bit[i] = 0;
		for( int i = 1; i <= n; i++ ){
			scanf("%d%d%d", &p[i], &r[i], &t[i] );
			if( p[i] != -1 ) adj[p[i]].pb( i );
			else root = i;
		}
		dfs( root );
		for( int i = 1; i <= n; i++ ) printf("%lld\n", ans[i] );
	}
}

