#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int n;
vector<ii> adj[100100];
set<int> st[100100];

int dijkstra(){
	int dist[100100];
	priority_queue<ii> pq;
	memset( dist, 0x3f3f3f3f, sizeof dist);
	dist[1] = 0;
	pq.push( ii( 0, 1 ) );
	while( !pq.empty() ){
		int u = pq.top().second;
		int d = -pq.top().first;
		pq.pop();
		if( u == n ) return dist[u];
		if( d != dist[u] ) continue;
		int k;
		for( k = 0; st[u].count(d+k); k++ );
		for( auto aux : adj[u] ){
			int v = aux.first, d_u_v = aux.second;
			if( dist[v] > dist[u]+k+d_u_v ){
				dist[v] = dist[u]+k+d_u_v;
				pq.push( ii( -dist[v], v ) );
			} 
		}
	}
	return -1;
}

int main(){
	int m, a, b, c;
	scanf("%d%d", &n, &m );
	while( m-- ){
		scanf("%d%d%d", &a, &b, &c );
		adj[a].pb( ii( b, c ) );
		adj[b].pb( ii( a, c ) );
	}
	rep( i, 1, n+1 ){
		scanf("%d", &a );
		rep( j, 0, a ){
			scanf("%d", &b );
			st[i].insert(b);
		}
	}
	cout << dijkstra() << endl;
}

