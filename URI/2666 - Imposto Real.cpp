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
#define N 25000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int sum[N], C, ans;
vector<ii> adj[N];

void dfs( int u, int p, int w ){
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i].F;
		int c = adj[u][i].S;
		if( v == p ) continue;
		dfs( v, u, c );
	}
	ans += (( sum[u] + C-1 )/C ) * w;
	sum[p] += sum[u];
}

int main(){
	int n, u, v, c;
	while( scanf("%d%d", &n, &C ) != EOF ){
		rep( i, 1, n+1 ) scanf("%d", &sum[i] ), adj[i].clear();
		ans = 0;
		rep( i, 1, n ){
			scanf("%d%d%d", &u, &v, &c );
			adj[u].pb( ii( v, c ));
			adj[v].pb( ii( u, c )); 
		}
		dfs( 1, 0, 0 );
		printf("%d\n", ans*2 );
	}
}

