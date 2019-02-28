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

const int N = 1e6+42;

int vis[N];
vector<int> adj[N];

void dfs( int u ){
	if( vis[u] ) return;
	vis[u] = 1;
	rep( i, 0, adj[u].size() ) dfs( adj[u][i] );
}

int main(){
	int n, m, u, v;
	while( scanf("%d%d", &n, &m ) != EOF ){
		rep( i, 0, n ) vis[i] = 0, adj[i].clear();
		while( m-- ){
			scanf("%d%d", &u, &v );
			u--, v--;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		int cnt = 0;
		rep( i, 0, n ){
			if( !vis[i] ) cnt++, dfs(i);
		}
		printf("%d\n", cnt );
	}
}

