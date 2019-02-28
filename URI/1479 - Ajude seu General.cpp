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

const int N = 1100;

vector<ii> adj[N];
vector<int> adj2[N];
int dist[N], pai[N];
priority_queue<ii> pq;

void dijkstra(){
	while( !pq.empty() ){
		int u = pq.top().S;
		int c = -pq.top().F;
		pq.pop();
		if( dist[u] != c ) continue;
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i].F;
			int d_u_v = adj[u][i].S;
			if( dist[v] > c + d_u_v ){
				dist[v] = c + d_u_v;
				pai[v] = u;
				pq.push( ii( -dist[v], v ));
			}
		}
	}
}

void dfs( int u ){
	if( dist[u] == INF ) return;
	dist[u] = INF;
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i].F;
		if( pai[v] == u ) dfs( v );
	}
	rep( i, 0, adj2[u].size() ){
		int v = adj2[u][i];
		pq.push( ii( -dist[v], v ) );
	}
}

int main(){
	
	int n, m, u, v, c, q;
	char op;
	while( scanf("%d%d", &n, &m ) != EOF ){
		if( !n && !m ) break;
		rep( i, 0, n+1 ){
			dist[i] = INF;
			pai[i] = -1;
			adj[i].clear();
			adj2[i].clear();
		}
		
		while( m-- ){
			scanf("%d%d%d", &u, &v, &c );
			adj[u].pb( ii( v, c ) );
			adj2[v].pb(u);
		}
		dist[1] = 0;
		pq.push( ii( 0, 1 ) );
		dijkstra();
		scanf("%d", &q );
		while( q-- ){
			cin >> op;
			switch( op ){
				case 'P':{
					scanf("%d", &u );
					if( dist[u] >= INF ) printf("-1\n");
					else printf("%d\n", dist[u] );
					break;
				}
				case 'R':{
					scanf("%d%d", &u, &v );
					
					rep( i, 0, adj[u].size() ){
						int w = adj[u][i].F;
						if( w == v ) adj[u].erase( adj[u].begin() + i );
					}
					
					rep( i, 0, adj2[v].size() ){
						int w = adj2[v][i];
						if( w == v ) adj2[v].erase( adj2[v].begin() + i );
					}
					
					if( pai[v] == u ) dfs( v );
					
					dijkstra();
					break;
				}
				case 'I':{
					scanf("%d%d%d", &u, &v, &c );
					adj[u].pb( ii( v, c ));
					adj2[v].pb( u );
					if( dist[u] + c < dist[v] ){
						dist[v] = dist[u] + c;
						pq.push( ii( -dist[v], v ) );
						pai[v] = u;
						dijkstra();
					}
					break;
				}
			}
		}
		printf("\n");
	}
	
}

