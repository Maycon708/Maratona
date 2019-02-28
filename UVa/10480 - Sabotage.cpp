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

const int N = 110;

int flow[N][N], source, sink, n, pai[N];
vector<int> adj[N];

void init(){	
	rep( i, 0, n ){
		adj[i].clear();
		rep( j, 0, n ) flow[i][j] = 0;
	}
}

inline bool bfs(){
	queue <int> q;
	q.push( source );
	int vis[N];
	rep( i, 0, n ) vis[i] = 0, pai[i] = -1;
	while( !q.empty() ){
		int u = q.front(); q.pop();
		vis[u] = 1;
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i];
			if( flow[u][v] <= 0 || vis[v] ) continue;
			pai[v] = u;
			q.push( v );
		}
	}
	return vis[sink];	
}

int maxFlow(){
	int maxF = 0;
	while( bfs() ){
		int u = sink;
		int minF = INF; 
		while( pai[u] != -1 ){
			minF = min( minF, flow[pai[u]][u] );
			u = pai[u];
		}
		maxF += minF;
		u = sink;
		while( pai[u] != -1 ){
			flow[u][pai[u]] += minF;
			flow[pai[u]][u] -= minF;
			u = pai[u];
		}
	}
	return maxF;
}

bool vis[N];
vector<int> aux;

void dfs( int u ){
	if( vis[u] ) return;
	vis[u] = 1;
	aux.pb(u);
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i];
		if( !vis[v] && flow[u][v] > 0 ) dfs(v);
	}
}

int main(){
	int t = 1;
	int u, v, c, m;
	while( scanf("%d%d", &n, &m ) != EOF ){
		if( !n ) break;
		init();
		source = 0, sink = 1;
		memset( vis, 0, sizeof vis );
		while( m-- ){
			scanf("%d%d%d", &u, &v, &c );
			u--, v--;
			flow[u][v] += c;
			flow[v][u] += c;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		int f = maxFlow();
		dfs( source );
		rep( i, 0, aux.size() ){
			int u = aux[i];
			rep( i, 0, adj[u].size() ){
				int v = adj[u][i];
				if( vis[v] ) continue;
				if( flow[u][v] <= 0 ) printf("%d %d\n", u+1, v+1 );
			}
		}
		aux.clear();
		printf("\n");
	}
}

