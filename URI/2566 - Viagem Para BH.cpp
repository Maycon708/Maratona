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

vector<ii> adj[2][111];
int n, m;

int dijkstra( int id ){
	
	priority_queue<ii> pq;
	pq.push( ii( 0, 1 ) );
	vector<int> dist(111, INF);
	dist[1] = 0;
	
	while( !pq.empty() ){
		int u = pq.top().S;
		int c = -pq.top().F;
		pq.pop();
		if( dist[u] != c ) continue;
		if( u == n ) return c;
		rep( i, 0, adj[id][u].size() ){
			int v = adj[id][u][i].F;
			int d_u_v = adj[id][u][i].S;
			if( dist[v] > dist[u] + d_u_v ){
				dist[v] = dist[u] + d_u_v;
				pq.push( ii( -dist[v], v ) );
			}
		}
	
	}
	return INF;
}

int main(){
	int u, v, t, r;
	while( scanf("%d%d", &n, &m ) != EOF ){
		rep( i, 0, n+1 ) adj[0][i].clear(), adj[1][i].clear();
		while( m-- ){
			scanf("%d%d%d%d", &u, &v, &t, &r );
			adj[t][u].pb( ii( v, r ) );
		}
		printf("%d\n", min( dijkstra(0), dijkstra(1) ) );
	}
}
