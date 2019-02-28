#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
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
typedef pair <int, int> ii;

vector<int> adj[100100];
int cnt, vis[100100], cmp[100100], sz_cmp[100100], t_cmp[100100];

void dfs( int u, int t ){
	if( vis[u] ) return;
	vis[u] = 1;
	if( t_cmp[cmp[u]] < t ) sz_cmp[u] = 0;
	sz_cmp[cmp[u]]++;
	t_cmp[cmp[u]] = t;
	for( auto v : adj[u] ){
		dfs(v, t);
	}
}

int tam[100100], mat[505][505];

int main(){
	
	int n, m, k, a, b, c;
	
	scanf("%d%d%d", &n, &m, &k );
	
	rep( i, 0, k ) scanf("%d", &tam[i] );
	
	int aux = tam[0];
	for( int i = 1, j = 0; i <= n; i++ ){
		cmp[i] = j;
		if( i == aux ) j++, aux += tam[j];
	}
	rep( i, 0, k ) rep( j, 0, k ) if( i != j ) mat[i][j] = INF;
	
	rep( i, 0, m ){
		scanf("%d%d%d", &a, &b, &c );
		if( !c ){
			adj[a].pb(b);
			adj[b].pb(a);
		}
		a = cmp[a], b = cmp[b];
		if( a != b )
			mat[b][a] = mat[a][b] = min( mat[a][b], c );
	}
	
	bool check = 1;
	for( int i = 1; i <= n; i++ ){
		if( !sz_cmp[cmp[i]] ){
			dfs( i, i );
		}
	}
	rep( i, 0, k ){
		if( sz_cmp[i] != tam[i] ) check = 0;
	}
	if( !check ){
		puts("No");
		return 0;
	}
	puts("Yes");
	
	rep( c, 0, k ) rep( a, 0, k ) rep( b, 0, k ) mat[a][b] = min( mat[a][b], mat[a][c] + mat[c][b] );
	rep( i, 0, k ){
		rep( j, 0, k ) printf("%d ", mat[i][j] == INF ? -1 : mat[i][j] );
		printf("\n");
	}
}	

