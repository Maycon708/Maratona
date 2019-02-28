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

#define N 1111

int dist[N];
vector<ii> adj[N];

int dijkstra( int q ){
	priority_queue<ii> pq;
	memset( dist, INF, sizeof dist );
	
	int u;
	while( q-- ){
		scanf("%d", &u );
		u--;
		dist[u] = 0;
		pq.push( ii( 0, u ) );
	}
	int ans = 0;
	while( !pq.empty() ){
		u = pq.top().S;
		int d = -pq.top().F;
		pq.pop();
		if( dist[u] != d ) continue;
		ans = max( ans, d );
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i].F;
			int d_u_v = adj[u][i].S;
			if( dist[v] > d + d_u_v ){
				dist[v] = d + d_u_v;
				pq.push( ii( -dist[v], v ));
			}
		}
		adj[u].clear();
	}
	return ans;
}

int main(){
	int n, m, q, u, v, d;
	while( scanf("%d%d%d", &n, &m, &q ) != EOF && n ){
		while( m-- ){
			scanf("%d%d%d", &u, &v, &d );
			u--, v--;
			adj[u].pb( ii( v, d ) );
			adj[v].pb( ii( u, d ) );
		}
		printf("%d\n", dijkstra(q) );
	}
}

