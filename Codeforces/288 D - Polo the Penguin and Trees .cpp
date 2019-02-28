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

#define N 80010

ll n, sub[N];
vector<int> adj[N];

ll C( ll n ){
	return ( n * ( n-1 )) >> 1;
}

ll dfs( int u, int last ){
	ll ans = 0, tmp = 0;
	sub[u] = 1;
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i];
		if( v == last ) continue;
		ans += dfs( v, u );
		tmp += sub[u] * sub[v];
		sub[u] += sub[v];
	}
	return ans + tmp * ( tmp + 2LL * sub[u] * ( n - sub[u] ) );
}

int main(){
	int u, v;
	while( scanf("%I64d", &n ) != EOF ){
		for( int i = 1; i <= n; i++ ) adj[i].clear(), sub[i] = 0;
		for( int i = 1; i < n; i++ ){
			scanf("%d%d", &u, &v );
			adj[u].pb(v);
			adj[v].pb(u);
		}
		printf("%I64d\n", C(n) * C(n) - dfs(1, 0) );
	}

}

