#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int vis[202], cor[202];
vector<int> adj[202];

int bfs( int u ){
	queue<ii> q;
	q.push( ii( u, 0 ) );
	cor[u] = 0;
	int a = 0, b = 0;
	while( !q.empty() ){
		int u = q.front().F;
		int c = q.front().S;
		q.pop();
		if( cor[u] != c ) return 202;
		if( vis[u] ) continue;
		vis[u] = 1;
		if( !c ) a++;
		else b++;
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i];
			if( cor[v] == -1 ) cor[v] = 1 - cor[u];
			q.push( ii( v, 1 - cor[u] ));
		}
	}
	if( a > b && b ) swap( a, b );
	return a;
}

int main(){
	int t, n, m, u, v;
	scanf("%d", &t );
	while( t-- ){
		scanf("%d%d", &n, &m );
		rep( i, 0, n ) adj[i].clear(), vis[i] = 0, cor[i] = -1;
		while( m-- ){
			scanf("%d%d", &u, &v );
			adj[u].pb(v);
			adj[v].pb(u);
		}
		int ans = 0;
		rep( i, 0, n ){
			if( vis[i] ) continue;
			ans += bfs(i);
		}
		printf("%d\n", ( ans >= 202 ) ? -1 : ans );
	}
}

