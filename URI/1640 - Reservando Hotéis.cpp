#include <bits/stdc++.h>
//#include <unordered_map>

 #define INF 0x3F3F3F3F
 #define rep(i, a, b) for(int i = int(a); i < int(b); i++)
 #define it(i, a)  for( typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
 #define pb push_back
 #define pi 3.1415926535897932384626433832795028841971
 #define debug(x) cout << #x << " = " << x << endl;
 #define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
 #define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
 #define all(S) (S).begin(), (S).end()
 #define MAXV 10100
 #define MAXN 110
 #define F first
 #define S second
 #define EPS 1e-9
 #define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

ll readInt();

vector<ii> adj[MAXV];
bool hotel[MAXV], vs[MAXV];
int dist[MAXV];

int bfs( int n ){
	queue<ii> q;
	q.push( ii( 1, 0 ) );
	while( !q.empty() ){
		int u = q.front().F;
		int c = q.front().S;
		q.pop();
		if( vs[u] ) continue;
		vs[u] = 1;
		priority_queue<ii> pq;
		pq.push( ii( 0, u ));
		map < int, bool > vis;
		dist[u] = 0;
		while( !pq.empty() ){
			int v = pq.top().S;
			pq.pop();
			if( vis[v] ) continue;
			if( dist[v] > 600 ) break;
			vis[v] = 1;
			if( hotel[v] ) q.push( ii( v, c+1 ) );
			if( v == n ) return c;
			rep( i, 0, adj[v].size() ){
				int w = adj[v][i].F;
				int d_v_w = adj[v][i].S;
				if( dist[w] > dist[v] + d_v_w ){
					dist[w] = dist[v] + d_v_w;
					pq.push( ii( -dist[w], w ) );
				}
			}
		} 
	}
	return -1;
}

int main(){
	
	int	 n, h, u, m, v, c;
	while( 1 ){
		n = readInt();
		if( !n ) break;
		rep( i, 0, n+1 ){
			adj[i].clear();
			hotel[i] = 0;
			vs[i] = 0;
			dist[i] = INF;
		}
		h = readInt();
		rep( i, 0, h ){
			u = readInt();
			hotel[u] = 1; 
		}
		m = readInt();
		while( m-- ){
			u = readInt(); v = readInt(); c = readInt();
			adj[u].pb( ii( v, c ));
			adj[v].pb( ii( u, c ));
		}
		printf("%d\n", bfs( n ) );
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

