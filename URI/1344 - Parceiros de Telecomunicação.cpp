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

int n, k, g[1100];
vector < int > adj[1110];

void topologic(){
	queue < int > q;
	vector< int > vis( n, 0 );
	rep( i, 0, n )
		if( g[i] < k ) q.push( i );
	while( !q.empty() ){
		int u = q.front(); q.pop();
		if( vis[u] ) continue;
		vis[u] = 1;
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i];
			g[v]--;
			if( g[v] < k ) q.push( v );
		}
	}
}

bool vis[1110];

int dfs( int u ){
	int ans = 1;
	vis[u] = 1;
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i];
		if( g[v] >= k && !vis[v] ) ans += dfs( v );
	}
	return ans;
}

int main(){

	int m, u, v, ans;
	while( scanf("%d%d%d", &n, &m, &k ) != EOF ){
		if( !n ) break;
		rep( i, 0, n ) adj[i].clear(), vis[i] = g[i] = 0;
		while( m-- ){
			scanf("%d%d", &u, &v );
			u--, v--;
			adj[u].pb( v );
			adj[v].pb( u );
			g[u]++, g[v]++;
		}
		topologic();
		ans = 0;
		rep( i, 0, n ){
			if( !vis[i] && g[i] >= k )
				ans = max( ans, dfs( i ) );
		} 
		printf("%d\n", ans );
	}
	
}
