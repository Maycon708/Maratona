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

int vis[N], vis2[N];
vector<int> adj[N], adj2[N];

void dfs( int u ){
	if( vis[u] ) return;
	vis[u] = 1;
	rep( i, 0, adj[u].size() ) dfs( adj[u][i] );
}

void dfs2( int u ){
	if( vis2[u] ) return;
	vis2[u] = 1;
	rep( i, 0, adj2[u].size() ) dfs2( adj2[u][i] );
}


int main(){
	int n, u, v;
	while( scanf("%d", &n ) != EOF ){
		rep( i, 0, n ){
			scanf("%d%d", &u, &v );
			u--, v--;
			adj[u].pb(v);
			adj2[v].pb(u);
		}
		dfs(0); dfs2(0);
		bool ans = 1;
		rep( i, 0, n ){
			ans &= vis[i] & vis2[i];
			vis[i] = vis2[i] = 0;
			adj[i].clear(), adj2[i].clear();
		}
		if( ans ) printf("S\n");
		else printf("N\n");
	}
}

