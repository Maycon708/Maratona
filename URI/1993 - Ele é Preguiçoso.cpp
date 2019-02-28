#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 101000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);


using namespace std;

typedef pair <int, int> ii;
typedef pair <double, int> di;
typedef pair <int, double> id;
typedef long long int ll;

ll readInt();

vector< id > adj[MAXV];
double dist[MAXV];
bool vis[MAXV];
double dikstra( int ini, int fim ){
	rep( i, 0, fim+1){
		dist[i] = INF;
		vis[i] = 0;
	}
	priority_queue< di > pq;
	dist[ini] = 0;
	pq.push( di( 0, ini ) );
	while( !pq.empty() ){
		int u = pq.top().S; pq.pop();
		if( vis[u] ) continue;
		vis[u] = 1;
		if( u == fim ) return dist[u];	
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i].F;
			double d_u_v = adj[u][i].S;
			if( dist[v] > dist[u] + d_u_v ){
				dist[v] = dist[u] + d_u_v;
				pq.push( di( -dist[v], v ) );
			}
		} 
	}
}

int main(){
	int x[MAXV], y[MAXV], f[MAXV];

	while( 1 ){
		int n = readInt()+1;
		int px = readInt();
		int py = readInt();
		int lx = readInt();
		int ly = readInt();
		if( !n ) break;
		rep( i, 0, n+1 ) adj[i].clear();
		rep( i, 1, n ){
			x[i] = readInt();
			y[i] = readInt();
			f[i] = readInt();
			double dist = hypot( x[i] - px, y[i] - py );
			adj[0].pb( id( i, dist ) );
			adj[i].pb( id( 0, dist ) );
			dist = hypot( x[i] - lx, y[i] - ly );
			adj[n].pb( id( i, f[i] ) );
			adj[i].pb( id( n, fabs( dist - f[i] ) ) );
		}
		rep( i, 1, n ){
			rep( j, i+1, n ){
				double dist = hypot( x[i] - x[j], y[i] - y[j] );
				adj[i].pb( id( j, fabs( dist - f[i] ) ) );
				adj[j].pb( id( i, fabs( dist - f[j] ) ) );
			}
		}
		double dist = hypot( px - lx, py - ly );
		adj[0].pb( id( n, dist ) );
		adj[n].pb( id( 0, dist ) );
		printf("%.2f\n", dikstra( 0, n ) );
	}
}

ll readInt (){
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

