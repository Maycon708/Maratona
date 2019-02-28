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

#define N 10010

vector<ii> adj[N];

int dijkstra( int ini, int fim ){
	vector<int> dist(N, INF);
	dist[ini] = 0;
	priority_queue<ii> pq;
	pq.push( ii( 0, ini ) );
	while( !pq.empty() ){
		int u = pq.top().S;
		int d = -pq.top().F;
		pq.pop();
		if( dist[u] != d ) continue;
		if( u == fim ) return d;
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i].F;
			int duv = adj[u][i].S;
			if( d + duv < dist[v] ){
				dist[v] = d + duv;
				pq.push( ii( -dist[v], v ) );
			}
		}
	}
	return INF;
}

int main(){
	
	int c, s, a, b, u, v;
	
	while( scanf("%d%d%d%d", &c, &s, &a, &b ) != EOF ){
		rep( i, 0, c+1 ) adj[i].clear();
		while( s-- ){
			scanf("%d%d", &u, &v );
			adj[u].pb( ii( v, 0 ) );
			adj[v].pb( ii( u, 1 ) );
		}
		int aa = dijkstra( a, b );
		int bb = dijkstra( b, a );
		if( aa < bb ) printf("Bibi: %d\n", aa );
		else if( bb < aa ) printf("Bibika: %d\n", bb );
		else puts("Bibibibika");
	} 

}
