#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 250
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int C1, C2, source, sink, n;

const int maxN = 250;
const int maxE = 40111;
const int inf = 1000000005;

int nnode, nedge, src, snk;
int Q[ maxN ], pro[ maxN ], fin[ maxN ], dist[ maxN ];
int flow[ maxE ], cap[ maxE ], _cap[ maxE ], to[ maxE ], nxt[ maxE ];

void init( int _nnode, int _src, int _snk ) {
	nnode = _nnode, nedge = 0, src = _src, snk = _snk;
	FOR(i,1,nnode) fin[i] = -1;
}

void addEdge( int a, int b, int c1 = INF, int c2 = 0 ) {
	to[nedge]=b, _cap[nedge]=c1, flow[nedge]=0, nxt[nedge]=fin[a], fin[a]=nedge++;
	to[nedge]=a, _cap[nedge]=c2, flow[nedge]=0, nxt[nedge]=fin[b], fin[b]=nedge++;
}

bool bfs() {
	SET( dist, -1 );
	dist[src] = 0;
	int st = 0, en = 0;
	Q[en++] = src;
	while( st < en ) {
		int u = Q[ st++ ];
		for(int e = fin[u]; e >= 0; e = nxt[e] ) {
			int v = to[e];
			if( flow[e] < cap[e] && dist[v] == -1 ) {
				dist[v] = dist[u] + 1;
				Q[en++] = v;
			}
		}
	}
	return dist[snk] != -1;
}


int dfs(int u, int fl) {
	if( u == snk ) return fl;
	for( int& e = pro[u]; e >= 0; e = nxt[e] ) {
		int v = to[e];
		if( flow[e] < cap[e] && dist[v] == dist[u]+1 ) {
			int x = dfs( v, min( cap[e] - flow[e] , fl ) );
			if( x > 0 ) {
				flow[ e ] += x, flow[ e^1 ] -= x;
				return x;
			}
		}
	}
	return 0;
}

ll dinic() {
	rep( i, 0, nedge ) cap[i] = _cap[i], flow[i] = 0;
	ll ret = 0;
	while( bfs() ) {
		FOR(i, 1, nnode) pro[i] = fin[i];
		while( 1 ) {
			int delta = dfs( src, inf );
			if( !delta ) break;
			ret += delta;
		}
	}
	return ret;
}

inline int R( int u ){
	return 2*u+1;
}

inline int L( int u ){
	return R(u) + 1;
}

int main(){
	
	int t, m, a[N], b[N], c, aux, test = 1;
	scanf("%d", &t );
	while( t-- ){
		nedge = 0;
		scanf("%d%d", &n, &m );
		source = R(n), sink = L(n);
		C1 = R(n+1), C2 = L(n+1);
		init( C2, source, sink );
		int total = 0;
		rep( i, 0, n ){
			scanf("%d%d%d", &a[i], &b[i], &c );
			c = (( c + m - 1 )/m)*m;
			addEdge( source, R(i), c );
			addEdge( R(i), C1 );
			addEdge( C2, L(i) );
			addEdge( L(i), sink, c );
			total += c;
		}
		rep( i, 0, n ){
			rep( j, 0, n ){
				scanf("%d", &aux );
				if( b[i] + aux < a[j] ){
					addEdge( R(i), L(j) );
				}
			}
		}
		addEdge( C1, C2, total );
		int i = 0, j = total/m, ans = total/m;
		while( i <= j ){
			int mid = ( i + j )/2;
			_cap[nedge-2] = m*mid;
			if( dinic() == total ) j = mid-1, ans = min( ans, mid );
			else i = mid+1;
		}
		printf("Case %d: %d\n", test++, ans );
	}
}
