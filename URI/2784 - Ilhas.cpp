#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

vector<ii> adj[1010];
int dist[1010];

int dijkstra( int s, int n ){
	
	dist[s] = 0;
	priority_queue<ii> pq;
	pq.push( ii(0, s) );
	while( !pq.empty() ){
		int u =  pq.top().S;
		int c = -pq.top().F;
		pq.pop();
		if( dist[u] != c ) continue;
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i].F;
			int d_u_v = adj[u][i].S;
			if( dist[v] > dist[u] + d_u_v ){
				dist[v] = dist[u] + d_u_v;
				pq.push( ii( -dist[v], v ) );
			}
		}
	}
	int mx = 0, mn = INF;
	rep( i, 0, n ){
		if( i != s ){
			mx = max( mx, dist[i] );
			mn = min( mn, dist[i] );
		}
	}
	return mx-mn;
}

int main(){
	int n, m, a, b, c, s;
	while( scanf("%d%d", &n, &m ) != EOF ){
		rep( i, 0, n ) adj[i].clear(), dist[i] = INF;
		while( m-- ){
			scanf("%d%d%d", &a, &b, &c );
			a--, b--;
			adj[a].pb( ii(b, c) );
			adj[b].pb( ii(a, c) );
		}
		scanf("%d", &s ); s--;
		printf("%d\n", dijkstra(s, n) );
	}
}
