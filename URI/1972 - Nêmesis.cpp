#include <bits/stdc++.h>
        
#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debug3(x,y,z) cout << #x << " = " << x << " --- " << #y << " " << y << " --- " << #z << " " << z << "\n";
#define debugV(a, b) { for( int i = 0; i < b; i ++ ) cout << a[i] << " "; cout << endl; }
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair
#define MAXV 500*500+1
        
using namespace std;
        
typedef unsigned long long ll;
typedef pair < int, int >  ii;

int K, n, m;
char mat[600][600];
vector < ii > adj[MAXV];

inline bool dentro( int x, int y ){
	return x >= 0 && y >= 0 && x < n && y < m && mat[x][y] != '#';
}

int dijkstra( int ini, int fim ){
	bool vis[MAXV];
	int dist[MAXV];
	rep( i, 0, K ){
		vis[i] = 0;
		dist[i] = INF;
	}
	dist[ini] = 0;
	priority_queue < ii > pq;
	pq.push( ii( 0, ini ) );
	while( !pq.empty() ){
		int u = pq.top().S;
		int c = -pq.top().F;
		//debug2( u, c )
		pq.pop();
		if( u == fim ) return c;
		if( vis[u] ) continue;
		vis[u] = 1;
		rep( i, 0, adj[u].size() ){
			int d_u_v = adj[u][i].S;
			int v = adj[u][i].F;
	//		debug2( v, d_u_v )
			if( dist[u] + d_u_v < dist[v] ){
				dist[v] = dist[u] + d_u_v;
				pq.push( ii( -dist[v], v ) );
			}
		}
	}
	return -1;
}

inline int C( char c ){
	if( c >= '0' && c <= '9' ){
		return c-'0';
	}
	return 0;
}

int main(){
	int dx[] = { 1, -1, 0, 0 };
	int dy[] = { 0, 0, -1, 1 };
	int ini, fim, mp[600][600];
	while( scanf("%d%d", &n, &m ) != EOF ){
		K = 0;
		rep( i, 0, n ){
			rep( j, 0, m ){
				scanf(" %c", &mat[i][j] );
				mp[i][j] = K++;
				if( mat[i][j] == 'H' ) ini = mp[i][j];
				if( mat[i][j] == 'E' ) fim = mp[i][j];
			}
		}
		rep( i, 0, K ) adj[i].clear();
		rep( i, 0, n ){
			rep( j, 0, m ){
				rep( k, 0, 4 ){
					int x = i + dx[k], y = j + dy[k];
					if( dentro( x, y ) ){
						adj[ mp[i][j] ].pb( ii( mp[x][y], C( mat[x][y] ) ) );
					}
				}		
			}
		}
		int resp = dijkstra( ini, fim );
		if( resp == -1 ) printf( "ARTSKJID\n" );
		else printf("%d\n", resp );
	}
}

