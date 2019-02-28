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

#define N 10010

int vis[N];
vector<int> adj[N];

int bfs( int u ){
	queue<ii> q;
	q.push( ii( u, -1 ) );
	while( !q.empty() ){
		int u = q.front().F;
		int p = q.front().S;
		q.pop();
		if( vis[u] ) return 0;
		vis[u] = 1;
		rep( i, 0, adj[u].size() ){
			int v = adj[u][i];
			if( v != p ) q.push( ii( v, u ) );
		}
	}
	return 1;
}

int main(){
	int n, m, u, v;
	while( scanf("%d%d", &n, &m ) != EOF ){
		rep( i, 0, n+1 ) adj[i].clear(), vis[i] = 0;
		while( m-- ){
			scanf("%d%d", &u, &v );
			adj[u].pb(v);
			adj[v].pb(u);
		}
		int ans = 1;
		for( int i = 1; i <= n && ans; i++ ){
			if( vis[i] ) continue;
			ans = bfs(i);
		}
		if( ans ) printf("Seguro\n");
		else printf("Inseguro\n");
	}
}

