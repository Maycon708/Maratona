#include <bits/stdc++.h>
     
#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define all(S) (S).begin(), (S).end()
#define MAXV 110015
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair
     
// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);
     
using namespace std;
     
typedef pair <int, int> ii;
typedef long long int ll;

int d[MAXV], n;
vector < ii > adj[MAXV], adj2[MAXV];

void dijkstra( int ini ){
    priority_queue < ii > pq;
    bool vis[MAXV];
    rep( i, 0, n+1 ){
        d[i] = INF;
        vis[i] = 0;
    }
    d[ini] = 0;
    pq.push( mk( 0, ini ) );
    while( !pq.empty() ){
        int u = pq.top().S;
        int c = -pq.top().F;
        pq.pop();
        if( vis[u] ) continue;
        vis[u] = 1;
        rep( i, 0, adj[u].size() ){
            int v = adj[u][i].F;
            int d_u_v = adj[u][i].S;
            if( d[v] > d[u] + d_u_v ){
                d[v] = d[u] + d_u_v;
                pq.push( mk( -d[v], v ) );
            }
        }
    }
}
int dijkstra2( int ini, int fim ){
    priority_queue < ii > pq;
    double dist[MAXV]; 
    bool vis[MAXV];
    rep( i, 0, n+1 ){
        dist[i] = INF;
        vis[i] = 0;
    }
    dist[ini] = 0;
    pq.push( mk( 0, ini ) );
    while( !pq.empty() ){
        int u = pq.top().S;
        int c = -pq.top().F;
        pq.pop();
        if( vis[u] ) continue;
        if( u == fim ) return dist[u];
        vis[u] = 1;
        rep( i, 0, adj2[u].size() ){
            int v = adj2[u][i].F;
            int d_u_v = adj2[u][i].S;
            if( dist[v] > dist[u] + d_u_v ){
                dist[v] = dist[u] + d_u_v;
                pq.push( mk( -dist[v], v ) );
            }
        }
    }
}

int main(){
	int c, s, m, e[MAXV], a, v, b, ini, fim;
	while( scanf("%d%d%d%d", &n, &c, &s, &m ) != EOF ){
		rep( i, 0, n+1 ) adj[i].clear(), adj2[i].clear();
		int cont = 0;
		while( c-- ){
			scanf("%d%d%d", &a, &b, &v );
			adj[a].pb( ii( b, v ) );
			adj[b].pb( ii( a, v ) );
			adj2[a].pb( ii( b, v ) );
			adj2[b].pb( ii( a, v ) );
		}
		while( s-- ){
			scanf("%d%d%d", &a, &b, &v );
			adj[a].pb( ii( b, v ) );
			adj[b].pb( ii( a, v ) );
		}
		rep( i, 0, m ){
			scanf("%d", &e[i] );
		}
		scanf("%d%d", &ini, &fim );
		int dist = dijkstra2( ini, fim );
		dijkstra( fim );
		rep( i, 0, m ){
			if( dist >= d[ e[i] ] ) cont++;
		}
		printf("%d\n", cont );
	}
}
