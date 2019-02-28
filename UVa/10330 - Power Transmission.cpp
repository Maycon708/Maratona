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

int in( int x ){
	return x << 1;
}
int out( int x ){
	return in(x) ^ 1;
}

int source = 0, sink = 1, flow[300][300], pai[300];
vector<int> adj[300];
bool vis[300];

inline bool bfs(){
	queue <int> q;
	q.push( source );
	rep( i, 0, 300 ) vis[i] = 0, pai[i] = -1;
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

void init(){
	memset( flow, 0, sizeof flow );
	rep( i, 0, 300 ) adj[i].clear();
}

int main(){
	int n, cap, u, v, m, b, d;
	while( scanf("%d", &n ) != EOF ){
		init();
		rep( i, 1, n+1 ){
			scanf("%d", &cap );
			u = in(i), v = out(i);
			flow[u][v] += cap;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		scanf("%d", &m );
		rep( i, 0, m ){
			scanf("%d%d%d", &u, &v, &cap );
			u = out(u), v = in(v);
			flow[u][v] += cap;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		scanf("%d%d", &b, &d );
		rep( i, 0, b ){
			scanf("%d", &u );
			u = in(u);
			flow[0][u] = INF;
			adj[0].pb(u);
			adj[u].pb(0);
		}
		rep( i, 0, d ){
			scanf("%d", &u );
			u = out(u);
			flow[u][1] = INF;
			adj[1].pb(u);
			adj[u].pb(1);
		}
		printf("%d\n", maxFlow() );
	}
}

