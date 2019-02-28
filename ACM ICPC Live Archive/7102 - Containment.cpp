#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define REP(i,b) rep(i,0,b)
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);
#define all(c) (c).begin(), (c).end()
#define UNIQUE(c) sort(all(c)); (c).resize(unique(all(c))-c.begin());
#define pb push_back
#define debug(x) cout<<__LINE__<<": "<<#x<<" = "<<x<<endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define mk make_pair
#define F first
#define S second
#define sz size()

typedef long long LL;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;

const int maxN = 60005;
const int maxE = 700111;
const int inf = 1000000005;

int nnode, nedge, src, snk;
int Q[ maxN ], pro[ maxN ], fin[ maxN ], dist[ maxN ];
int flow[ maxE ], cap[ maxE ], to[ maxE ], nxt[ maxE ];

void init( int _nnode, int _src, int _snk ) {
	nnode = _nnode, nedge = 0, src = _src, snk = _snk;
	FOR(i,1,nnode) fin[i] = -1;
}

void add( int a, int b, int c1, int c2 ) {
	to[nedge]=b, cap[nedge]=c1, flow[nedge]=0, nxt[nedge]=fin[a], fin[a]=nedge++;
	to[nedge]=a, cap[nedge]=c2, flow[nedge]=0, nxt[nedge]=fin[b], fin[b]=nedge++;
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
				flow[e] += x, flow[ e^1 ] -= x;
				return x;
			}
		}
	}
	return 0;
}
		
LL dinic() {
	LL ret = 0;
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

bool dentro( int x, int y, int z ){
	return x >= 0 && x < 10 && y >= 0 && y < 10 && z >= 0 && z < 10;
}

int aux[10][10][10], cnt;

void build(){
	init( cnt+3, 1, 2 );
	
	int dx[] = { -1, 1, 0, 0, 0, 0 };
	int dy[] = { 0, 0, -1, 1, 0, 0 };
	int dz[] = { 0, 0, 0, 0, -1, 1 };
	rep( x, 0, 10 ){
		rep( y, 0, 10 ){
			rep( z, 0, 10 ){
				rep( i, 0, 6 ){
					int xx = x + dx[i], yy = y + dy[i], zz = z + dz[i];
					if( !dentro( xx, yy, zz ) ) add( 1, aux[x][y][z], 1, 0 );
					else add( aux[x][y][z], aux[xx][yy][zz], 1, 0 );
				}
			}
		}
	}
	
}

int main(){
	
	cnt = 3;
	rep( i, 0, 10 ) 
		rep( j, 0, 10 )
			rep( k, 0, 10 )
				aux[i][j][k] = cnt++;
		
	int t, n, x, y, z;
	scanf("%d", &t );
	while(scanf("%d", &n ) != EOF ){
		build();
		while( n-- ){
			scanf("%d%d%d", &x, &y, &z );
			add( aux[x][y][z], 2, INF, 0 );
		}
		printf("%lld\n", dinic() );
	}
	return 0;
}
