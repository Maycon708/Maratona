#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 600
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);


using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

ll readInt();

int n;
vector < ii > adj[MAXV], adj2[MAXV];

int dijkstra( int dest, int ini ){
	int vis[MAXV], dist[MAXV], dist2[MAXV], pai[MAXV], menor[MAXV];
	rep( i, 0, n+1 ){
		vis[i] = 0;
		pai[i] = -1;
		menor[i] = 0;
		dist[i] = dist2[i] = INF;
	}
	priority_queue < ii > pq;
	pq.push( ii( 0, ini ) );
	dist[ini] = 0;
	while( !pq.empty() ){
		int u = pq.top().S;
		pq.pop();
		if( vis[u] ) continue;
		vis[u] = 1;
		rep( i, 0, adj2[u].size() ){
			int v = adj2[u][i].F;
			int d_u_v = adj2[u][i].S;
			if( dist[v] > dist[u] + d_u_v ){
				dist[v] = dist[u] + d_u_v;
				pai[v] = u;
				pq.push( ii( -dist[v], v ) );
			}
		}
	}
	int c = dist[dest];
	swap( dest, ini );
	dist2[dest] = c;
	int k = dest;
	if( c == INF ) return -1;
	while( dist2[dest] == c ){
		rep( i, 0, n ){
			dist2[i] = INF;
			vis[i] = 0;
			pai[i] = -1;
		}
		while( !pq.empty() ) pq.pop();
		pq.push( ii( 0, ini ) );
		dist2[ini] = 0;
		while( !pq.empty() ){
			int u = pq.top().S;
			pq.pop();
//			debug( u )
//			debug2( dist[u], dist2[u] )
//			getchar();
			if( dist[u] + dist2[u] == c && menor[u] ){
				k = u;
				dist2[dest] = c;
				break;
			}
			if( u == dest ) break;
			if( vis[u] ) continue;
			vis[u] = 1;
			rep( i, 0, adj[u].size() ){
				int v = adj[u][i].F;
				int d_u_v = adj[u][i].S;
				if( dist2[v] >= dist2[u] + d_u_v ){
					dist2[v] = dist2[u] + d_u_v;
					pai[v] = u;
					pq.push( ii( -dist2[v], v ) );
				}
			}
		}
		int x = k;
		while( pai[x] != -1 ){
			vector< ii > v;
			int u = pai[x];
			rep( i, 0, adj[u].size() ){
				if( adj[u][i].F != x ) v.pb( adj[u][i] );
			}
			menor[x] = 1;
			adj[u] = v;
			x = pai[x];
		}
	}
	if( dist2[dest] == INF ) return -1;
	return dist2[dest];
}

int main(){

	while( 1 ){
		n = readInt();
		int m = readInt();
		if( !n && !m ) break;
		rep( i, 0, n+1 ) adj[i].clear(), adj2[i].clear();
		int s = readInt();
		int d = readInt();
		while( m-- ){
			int u = readInt();
			int v = readInt();
			int c = readInt();
			adj[u].pb( ii( v, c ) );
			adj2[v].pb( ii( u, c ) );
		}
		printf("%d\n", dijkstra( s, d ) );	
	}

}

ll readInt () {
    bool minus = false;
    ll result = 0; char ch;

    ch = getchar();
    while (true) {
        if (ch == '-')
            break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-')  minus = true;
    else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch-'0');
    }
    if (minus) return -result;
    else return result;
}


