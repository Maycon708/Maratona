#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(ll i = ll(a); i < ll(b); i++)
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

typedef long long ll;
typedef pair <ll, ll> ii;

const ll N = 1111;

ll dano[N], dist[N], castle, n;
vector<ll> adj[N];

void dijkstra(){
	priority_queue<ii> pq;
	pq.push( ii( 0, castle ) );
	dist[castle] = 0;
	while( !pq.empty() ){
		ll u = pq.top().S;
		ll c = -pq.top().F;
		pq.pop();
		if( dist[u] != c ) continue;
		rep( i, 0, adj[u].size() ){
			ll v = adj[u][i];
			ll d_u_v = dano[v];
			if( dist[v] > c + d_u_v ){
				dist[v] = c + d_u_v;
				pq.push( ii( -dist[v], v ));
			}
		}
	}
}

void init(){
	rep( i, 0, n+1 ){
		adj[i].clear();
		dist[i] = INF;
		dano[i] = 0;
	}
}

bool vis[N];

void dfs( int u, int d, int a ){
	if( vis[u] || a < 0 || u == castle ) return;
	vis[u] = 1;
	dano[u] += d;
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i];
		dfs( v, d, a-1 );
	}
}

int main(){
	
	ll T, m, u, v, a, c, h, p, q, d;
	scanf("%lld", &T );
	
	rep( t, 1, T+1 ){
		scanf("%lld%lld%lld", &n, &m, &castle );
		init();
		while( m-- ){
			scanf("%lld%lld", &u, &v );
			adj[u].pb(v); adj[v].pb(u);
		}	

		scanf("%lld", &p );
		rep( i, 0, p ){
			rep( i, 0, n+1 ) vis[i] = 0;
			scanf("%lld%lld%lld", &v, &d, &a );
			dfs( v, d, a );
		}
		
		dijkstra();
		scanf("%lld", &q );
		ll cnt = 0;
		while( q-- ){
			scanf("%lld%lld", &v, &h );
			if( dist[v] < h ) cnt++;
		}
		printf("Caso #%lld: %lld\n", t, cnt );
	}
}
