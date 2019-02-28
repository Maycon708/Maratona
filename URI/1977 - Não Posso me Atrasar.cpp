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

const int N = 1010;

vector<ii> adj[N];
int dist[N];

int dijkstra( int ini, int fim ){
	priority_queue<ii> pq;
	memset( dist, INF, sizeof dist );
	dist[ini] = 0;
	pq.push( ii( 0, ini ) );
	while( !pq.empty() ){
		int u = pq.top().S;
		int c = -pq.top().F;
		pq.pop();
		if( dist[u] != c ) continue;
		if( u == fim ) return c;
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i].F;
			int d_u_v = adj[u][i].S;
			if( dist[v] > c + d_u_v ){
				dist[v] = c + d_u_v;
				pq.push( ii( -dist[v], v ));
			}
		}
	}
	return INF;
}

int main(){
	int x, n, m, u, v, c;
	char o[200], d[200];
	while( scanf("%d%d%d", &x, &n, &v ) != EOF ){
		if( !x && !n && !v ) break;
		map<string, int> mp;
		int k = 1;
		rep( i, 0, N ) adj[i].clear();
		while( n-- ){
			scanf(" %s %s %d", o, d, &c );
			if( !mp[o] ) mp[o] = k++;
			if( !mp[d] ) mp[d] = k++;
			adj[ mp[o] ].pb( ii( mp[d], c ) );
		}
		int mi = (17 * 60) + (dijkstra( mp["varzea"], mp["alto"] )) + (( x <= 30 ) ? 30 : 50);
		printf("%02d:%02d\n", mi/60, mi%60 );
		if( mi <= 18 * 60 ) puts("Nao ira se atrasar");
		else puts("Ira se atrasar");
	}
}
