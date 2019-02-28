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

#define N 1001

vector<ii> adj[N];
int t[N], dist[N][N];

void dijkstra( int ini ){
	priority_queue<ii> pq;
	pq.push( ii( 0, ini ) );
	dist[ini][ini] = 0;
	while( !pq.empty() ){
		int u = pq.top().S;
		int d = -pq.top().F;
		pq.pop();
		if( d != dist[ini][u] ) continue;
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i].F;
			int d_u_v = adj[u][i].S;
			if( dist[ini][v] > dist[ini][u] + d_u_v ){
				dist[ini][v] = dist[ini][u] + d_u_v;
				pq.push( ii(-dist[ini][v], v ) );
			}
		}
	}
}

int main(){
	int n, m, a, b, c;
	while( scanf("%d%d", &n, &m ) != EOF ){
		rep( i, 0, n ){
			scanf("%d", &t[i] );
			rep( j, 0, n ) adj[i].clear(), dist[i][j] = INF;
		}
		while( m-- ){
			scanf("%d%d%d", &a, &b, &c );
			a--, b--;
			adj[a].pb( ii( b, c + t[b] ) ); 
		}
		int ans = 1 << 30;
		rep( i, 0, n ) dijkstra(i);
		rep( i, 0, n )
			rep( j, i+1, n )
				ans = min( ans, dist[i][j] + dist[j][i] );
		printf("%d\n", ans );
	}
}	

