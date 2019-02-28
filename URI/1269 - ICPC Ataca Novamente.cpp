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

const int N = 1001;

int basico[N], vis[N], g[N], salary;
vector<int> adj[N], w[N];

void dfs1( int u ){
	if( vis[u] ) return;
	vis[u] = 1;
	g[u] = 0;
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i];
		dfs1(v);
		basico[u] += basico[v];
		g[u] = max( g[u], 1 + g[v] );
	}
}

void dfs( int u ){
	if( vis[u] ) return;
	vis[u] = 1;
	
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i];
		dfs(v);
	}
}

inline bool cmp( int a, int b ){
	return g[a] > g[b];
}

int main(){
	
	int t, e, ne, nd, v;
	
//	freopen("in.txt", "r", stdin );
	
	while( scanf("%d%d", &t, &e ) != EOF ){
		if( !t && !e ) break;
	
		rep( i, 1, t+1 ){
			scanf("%d%d%d", &basico[i], &nd, &ne );
			adj[i].clear();
			rep( j, 0, nd )
				scanf("%d", &v ),
				adj[i].pb(v); 
			
			rep( j, 0, ne )
				scanf("%d", &v ),
				w[v].pb(i);	
			vis[i] = 0;
		}
		
		rep( i, 1, t+1 ) if( !vis[i] ) dfs1(i);
		
		printf("*****\n");
		rep( i, 1, e+1 ){
			
			sort( all( w[i] ), cmp );
			memset( vis, 0, sizeof vis );
			salary = 0;
			
			rep( j, 0, w[i].size() ){
				int v = w[i][j];
				if( !vis[v] ){
					salary += basico[v];
					dfs(v);
				}
			}
			
			printf("%d %d\n", i, salary );
			w[i].clear();
		}
	}
}

