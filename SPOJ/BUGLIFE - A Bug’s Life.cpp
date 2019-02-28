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

const int N = 1000010;

vector<int> adj[N];
int vis[N], scc[N], nScc;
stack<int> s;

int neg( int u ){
	return u ^ 1;
}

void addEdge( int u, int v ){
	u--, v--;
	u <<= 1, v <<= 1;
	adj[neg(u)].pb(v);
	adj[neg(v)].pb(u);
	adj[u].pb(neg(v));
	adj[v].pb(neg(u));
}

void dfs1( int u ){
	if( vis[u] ) return;
	vis[u] = 1;
	rep( i, 0, adj[u].size() ){
		dfs1( adj[u][i] );
	}
	s.push(u);
}


void dfs2( int u ){
	if( scc[u] ) return;
	scc[u] = nScc;
	rep( i, 0, adj[u].size() ){
		dfs2( adj[u][i] );
	}
}

void init( int n ){
	nScc = 1;
	rep( i, 0, N ){
		adj[i].clear();
		vis[i] = scc[i] = 0;
	}
}

int main(){
	int t, n, m, u, v;
	scanf("%d", &t );
	rep( k, 1, t+1 ){
		init( n );
		scanf("%d%d", &n, &m );
		while( m-- ){
			scanf("%d%d", &u, &v );
			addEdge( u, v );
		}
		rep( i, 0, n << 1 ){
			if( !vis[i] ) dfs1( i );
		}
		while( !s.empty() ){
			int x = s.top(); s.pop();
			if( !scc[x] ){
				dfs2( x );
				nScc++;
			}
		}
		bool ok = 1;
		rep( i, 0, n ){
			int u = i << 1;
			if( scc[u] == scc[neg(u)]){
				ok = 0; break;
			}
		}
		printf("Scenario #%d:\n", k );
		if( ok ) printf("No suspicious bugs found!\n");
		else printf("Suspicious bugs found!\n");
	}
}

