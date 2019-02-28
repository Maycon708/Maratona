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

#define N 5005

int dist[3][N], vis[N], d1, d2;
vector<ii> adj[N];

void dijkstra( int op, int ini  ){
	dist[op][ini] = 0;
	priority_queue<ii> pq;
	pq.push( ii( 0, ini ) );
	while( !pq.empty() ){
		int u = pq.top().S;
		int c = -pq.top().F;
		pq.pop();
		if( dist[op][u] != c ) continue;
		rep( i, 0, adj[u].size() ){	
			int v = adj[u][i].F;
			int d_u_v = adj[u][i].S;
			if( dist[op][v] > c + d_u_v ){
				dist[op][v] = c + d_u_v;
				pq.push( ii( -dist[op][v], v ) );
			}
		}
	}
	
}

int dfs( int u ){
	if( vis[u] != -1 ) return vis[u];
	int ans = 0;
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i].F;
		int c = adj[u][i].S;
		if( dist[0][u] + c + dist[1][v] == dist[0][d1] && dist[0][u] + c + dist[2][v] == dist[0][d2]  )  ans = max( ans, dfs( v ) + c );
	}
	return vis[u] = ans;
}

int main(){
	
	int n, o, m, u, v, c;
	while( scanf("%d%d%d%d%d", &n, &o, &d1, &d2, &m ) != EOF ){
		o--, d1--, d2--;
		if( n == -1 ) break;
		rep( i, 0, n+1 ) adj[i].clear(), dist[0][i] = dist[1][i] = dist[2][i] = INF, vis[i] = -1;
		while( m-- ){
			scanf("%d%d%d", &u, &v, &c );
			u--, v--;
			adj[u].pb( ii( v, c ) );
			adj[v].pb( ii( u, c ) );
		}
		dijkstra( 0, o );
		dijkstra( 1, d1 );
		dijkstra( 2, d2 );
		int ans = dfs( o );
		printf("%d %d %d\n", ans, dist[0][d1] - ans, dist[0][d2] - ans );
	}		
	
}
