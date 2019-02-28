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

#define N 111

int n, dist[N];
vector<ii> adj[N];

int dijkstra( int ini ){
	priority_queue<ii> pq;
	pq.push( ii( 0, ini ));
	rep( i, 0, n ) dist[i] = INF;
	dist[ini] = 0;
	while( !pq.empty() ){
		int u = pq.top().S;
		int d = -pq.top().F;
		pq.pop();
		if( dist[u] != d ) continue;
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i].F;
			int d_u_v = adj[u][i].S;
			if( dist[v] > d + d_u_v ){
				dist[v] = d + d_u_v;
				pq.push( ii( -dist[v], v ) ); 
			}
		}
	}
	int ans = 0;
	rep( i, 0, n ){
		ans = max( ans, dist[i] );
	}
	return ans;
}

int main(){
	int m, u, v, c;
	while( scanf("%d%d", &n, &m ) != EOF && n ){
		rep( i, 0, n ) adj[i].clear();
		while( m-- ){
			scanf("%d%d%d", &u, &v, &c );
			adj[u].pb( ii( v, c ) );
			adj[v].pb( ii( u, c ) );
		}
		int ans = 1 << 30;
		rep( i, 0, n ) ans = min( ans, dijkstra(i) );
		printf("%d\n", ans );
	}
}

