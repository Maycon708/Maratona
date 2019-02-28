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

vector<ii> v, aux;
vector<int> adj[33];
int vis[33], pd[33][101][101][101], T;

void dfs( int u ){
	if( vis[u] ) return;
	vis[u] = 1;
	v.pb( aux[u] );
	rep( i, 0, adj[u].size() ) dfs( adj[u][i] );
}

int solve( int pos, int t, int a, int b ){
	if( pos == v.size() ) return (t==T) ? INF : abs(a-b);
	if( pd[pos][t][a][b] != -1 ) return pd[pos][t][a][b];
	int ans = solve( pos+1, t, a, b );
	if( t >= v[pos].F ){
		if( v[pos].S ) ans = min( ans, solve( pos, t - v[pos].F, a + v[pos].F, b ) );
		else ans = min( ans, solve( pos, t - v[pos].F, a, b + v[pos].F ) );
	}
	return pd[pos][t][a][b] = ans;
}

void init( int n ){
	aux.resize(n);
	v.clear();
	rep( i, 0, n ){
		adj[i].clear(); 
		vis[i] = 0;
	}
	memset( pd, -1, sizeof pd );
}

int main(){
	int n, x, m, u, p;
	char op;
	while( scanf("%d", &n ) != EOF ){
		init(n);
		scanf("%d", &T );
		rep( i, 0, n ){
			scanf("%d%d %c%d", &x, &p, &op, &m );
			aux[x] = ii( p, op == 'A' );
			rep( i, 0, m ){
				scanf("%d", &u );
				adj[x].pb(u);
			}
		}
		dfs(0);
		printf("%d\n", solve( 0, T, 0, 0 ) );
	}
}

