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

const int N = 100001;

vector<int> adj[N];
int d[N], pai[N][20], h[N];

int dfs( int u, int last, int deep ){
	h[u] = deep;
	
	pai[u][0] = last;
	rep( i, 1, 20 )
		pai[u][i] = pai[ pai[u][i-1] ][i-1];
	
	
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i];
		if( v == last ) continue;
		dfs( v, u, deep+1 );
	}
}

int lca( int u, int v ){
	int j;
	if( h[u] < h[v] ) swap( u, v );
	while( h[u] > h[v] ){
		j = 0;
		rep( i, 0, 20 ){
			if( h[ pai[u][i] ] < h[v] ) break;
			j = i;
		}
		u = pai[u][j];
	}
	while( u != v ){
		j = 0;
		rep( i, 0, 20 ){
			if( pai[u][i] == pai[v][i] ) break;
			j = i;
		}
		u = pai[u][j], v = pai[v][j];
	}
	return u;
}

void dfs2( int u, int last ){
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i];
		if( v == last ) continue;
		dfs2( v, u );
		d[u] += d[v]; 
	}
}

int main(){
	int t, n;
	scanf("%d", &t );
	rep( T, 1, t+1 ){
		memset( pai, 0, sizeof pai );
		scanf("%d", &n );
		rep( i, 0, n ) adj[i].clear(), d[i] = 0;
		rep( i, 1, n ){
			int u, v;
			scanf("%d%d", &u, &v );
			adj[u].pb(v);	adj[v].pb(u);
		}
		dfs( 0, 0, 0 );
		int q;
		scanf("%d", &q );
		while( q-- ){
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c );
			int w = lca( u, v );
			d[u] += c;
			d[v] += c;
			d[w] -= c;
			if( w ){
				d[ pai[w][0] ] -= c;
			}
		}
		dfs2( 0, -1 );
		printf("Case #%d:\n", T );
		rep( i, 0, n ){
			printf("%d\n", d[i] );
		}		
	}
}

