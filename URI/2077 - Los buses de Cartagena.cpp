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

const int maxN = 250;
const int maxE = 40111;
const int inf = 1000000005;

int nnode, nedge, src, snk;
int Q[ maxN ], pro[ maxN ], fin[ maxN ], dist[ maxN ];
int flow[ maxE ], cap[ maxE ], _cap[ maxE ], to[ maxE ], nxt[ maxE ];

void init( int _nnode, int _src, int _snk ) {
	nnode = _nnode, nedge = 0, src = _src+1, snk = _snk+1;
	FOR(i,1,nnode) fin[i] = -1;
}

void addEdge( int a, int b, int c1 = INF, int c2 = 0 ) {
	a++, b++;
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

int main(){
	
	int t, m, n;
	scanf("%d", &t );
	rep( test, 1, t+1 ){
		nedge = 0;
		scanf("%d%d", &n, &m );
		map<string, vector<int> > mp;
		int source = n+m+1, sink = n+m+2;
		init( n+m+5, source, sink );
		rep( i, 0, m ){
			char s[10];
			scanf("%s", s );
			mp[s].pb(i);
		}
		
		rep( i, 0, n ){
			char s[10]; int aux;
			scanf("%d", &aux );
			rep( j, 0, aux ){
				scanf("%s", s );
				if( !mp.count(s) ) continue;
				rep( k, 0, mp[s].size() ){
					addEdge( mp[s][k], i+m );
				}
			}
			addEdge( i+m, sink, 1 );
		}
		
		int aux = nedge;
		rep( i, 0, m ) addEdge( source, i );
		int ans = INF, i = 0, j = n;
		while( i <= j ){
			int mid = ( i + j + 1 )/2;
			for( int k = aux; k < nedge; k += 2 ) _cap[k] = mid;
				if( dinic() >= n ) j = mid-1, ans = min( ans, mid );
			else i = mid+1;
		}
		printf("%d\n", ans );
	}
}
