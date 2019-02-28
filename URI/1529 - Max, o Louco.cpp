#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
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

int n, t, pd[20][1100][60], V[20], vis[20][1<<11][60];
vector < ii > adj[20];

int solve( int l ){
//	debug2( pos, l )
//	getchar();
	priority_queue< pair < ii, ii > > pq;
	pq.push( mk( ii( 0, 0 ), ii( 1, l )));
	while( !pq.empty() ){
		int C = -pq.top().F.F;
		int u = pq.top().F.S;
		int mask = pq.top().S.F;
		int l = pq.top().S.S;
		pq.pop(); 
		if( vis[u][mask][l] ) continue;
		vis[u][mask][l] = 1;
		if( u == n-1 ) return C;
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i].F;
			int c = adj[u][i].S;
			if( l >= c ) 
				pq.push( mk( ii( -C, v ), ii( mask | ( 1 << v ), l-c )));
			rep( i, l, t ){
				if( i >= c ){
					int cc = ( i - l ) * V[u];		
					pq.push( mk( ii( -( C + cc ), v ), ii( mask | ( 1 << v), i-c )));
				}
			}
		}
	}
	return INF;
}

int main(){

	while( 1 ){
		n = readInt();
		int m = readInt();
		t = readInt();
		if( !n && !m && !t ) break;
		rep( i, 0, n+1 ) adj[i].clear();
		memset( vis, 0, sizeof vis );
		while( m-- ){
			int u = readInt()-1;
			int v = readInt()-1;
			int c = readInt();
			if( c > t ) continue;
			adj[u].pb( ii( v, c ) );
			adj[v].pb( ii( u, c ) );
		}
		rep( i, 0, n ) V[i] = readInt();
//		if( !bfs() ){
//			printf("-1\n");
//			continue;
//		}
		int ans = solve( t );
		if( ans == INF ) printf("-1\n");
		else printf("%d\n", ans );
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


