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

typedef long long int ll;
typedef pair <ll, ll> ii;

const int N = 1300031;

vector<ii> adj[N];
ll resp, g[N], n;

void dfs( int u, int last, int p ){
	g[u] = 1;
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i].F;
		int c = adj[u][i].S;
		if( v == last ) continue;
		dfs( v, u, c );
		g[u] += g[v];
	}
	ll a = ( g[u] * p )%N;
	resp += ( a * ( n - g[u] ) )%N;
	resp %= N;
}

int main(){
	int t, u, v, c;
	scanf("%d", &t );
	while( t-- ){
		scanf("%lld", &n );
		rep( i, 0, n ) adj[i].clear();
		resp = 0;
		rep( i, 1, n ){
			scanf("%d%d%d", &u, &v, &c );
			u--, v--;
			adj[u].pb(ii( v, c ));
			adj[v].pb(ii( u, c ));
		}
		dfs( 0, 0, 0 );
		printf("%lld\n", resp );
	}
}

