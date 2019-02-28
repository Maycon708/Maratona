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

const int N = 111;

int flow[N][N];
vector<ii> adj[N];
int dist[N];
int pai[N];
int source = 99, sink = 100;

void addEdge( int u, int v, int cap, int cost ){
	flow[u][v] = cap;
	adj[u].pb( ii( v, cost ));
	adj[v].pb( ii( u, -cost ));
}

inline bool dijkstra(){
	memset( pai, -1, sizeof pai );
	memset( dist, INF, sizeof dist );
	dist[source] = 0;
	priority_queue< ii > pq;
	pq.push( ii( 0, source ));
	while( !pq.empty() ){
		int u = pq.top().S;
		int c = -pq.top().F;
		pq.pop();
		if( dist[u] != c ) continue;
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i].F;
			int d_u_v = adj[u][i].S;
			if( flow[u][v] <= 0 ) continue;
			if( dist[v] > c + d_u_v ){
				dist[v] = c + d_u_v;
				pai[v] = u;
				pq.push( ii( -dist[v], v ) );
			}
		}
	}
	return dist[sink] != INF;
}

ii maxFlow(){
	int maxF = 0, cost = 0;
	while( dijkstra() ){
		int minF = INF, u = sink, v;
		while( pai[u] != -1 ){
			v = pai[u];
			minF = min( minF, flow[v][u] );
			u = v;
		}
		maxF += minF;
		cost += ( minF * dist[sink] );
		u = sink;
		while( pai[u] != -1 ){
			v = pai[u];
			flow[v][u] -= minF;
			flow[u][v] += minF;
			u = v;
		}
	}
	return ii( maxF, cost );
}

inline int in( int n ){
	return n << 1;
}

inline int out( int n ){
	return in(n)^1;
}

void init( int n ){
	memset( flow, 0, sizeof flow );
	rep( i, 0, N ) adj[i].clear();
}

int main(){
	int t, n, m, u, v, c, k;
	scanf("%d", &t );
	while( t-- ){
		scanf("%d%d%d", &n, &m, &k );
		init( n );
		while( m-- ){
			scanf("%d%d%d", &u, &v, &c );
			addEdge( in(u), out(v), 1, c );
		}
		rep( i, 0, n ){
			addEdge( source, in(i), k, 0 );
			addEdge( out(i), sink, k, 0 );
		}		
		ii a = maxFlow();
		if( a.F != n * k ) printf("-1\n");
		else printf("%d\n", a.S );
	}
}

