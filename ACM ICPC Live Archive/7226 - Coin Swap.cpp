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

const int N = 550;

int mat[N][N];
int pai[2*N];
int dist[2*N];
vector<ii> adj[2*N];
int flow[2*N][2*N];
int sink, source, n;

void floyd(){
	rep( k, 0, n ){
		rep( i, 0, n ){
			rep( j, 0, n ){
				if( i == j ) mat[i][j] = 0;
				mat[i][j] = min( mat[i][j], mat[i][k] + mat[k][j] );
			}
		}
	}
}

inline bool dijkstra(){
	memset( pai, -1, sizeof pai );
	memset( dist, INF, sizeof dist );
	priority_queue<ii> pq;
	dist[source] = 0;
	pq.push( ii( 0, source ) );
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
	ll maxF = 0, cost = 0;
	while( dijkstra() ){
		int u = sink, minF = INF;
		while( pai[u] != -1 ) 
			minF = min( minF, flow[pai[u]][u] ),
			u = pai[u];
		u = sink;
		maxF += minF;
		cost += ( dist[u] * minF );
		while( pai[u] != -1 )
			flow[u][pai[u]] += minF,
			flow[pai[u]][u] -= minF,
			u = pai[u];
	}
	return ii( maxF, cost );
}

void init(){
	rep( i, 0, 2*n ){
		adj[i].clear();
		rep( j, 0, 2*n ) 
			flow[i][j] = 0;
	}
	memset( mat, INF, sizeof mat );
}

void addEdge( int u, int v, int cap, int cost ){
	flow[u][v] += cap;
	adj[u].pb( ii( v, cost ) );
	adj[v].pb( ii( u, -cost ) );
}

int neg( int u ){
	return u^1;
}

int main(){
	int t, m, u, w, c[N], v[N];
	scanf("%d", &t );
	while( t-- ){
		scanf("%d%d", &n, &m );
		init();
		while( m-- ){
			scanf("%d%d", &u, &w );
			u--, w--;
			mat[u][w] = mat[w][u] = 1;
		}
		floyd();
		source = 2*n, sink = source+1;
		rep( i, 0, n ){
			scanf("%d", &v[i] );
			if( v[i] ) addEdge( source, 2*i, 1, 0 );
		}
		rep( i, 0, n ){
			scanf("%d", &c[i] );
			if( c[i] ){
				addEdge( neg(2*i), sink, 1, 0 );
				rep( j, 0, n ) if( v[j] ) addEdge( 2*j, neg(2*i), 1, mat[j][i] );
			}
		}
		ii a = maxFlow();
		printf("%d\n", a.S );
	}
}

