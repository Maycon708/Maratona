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

vector<int> adj[1111];
bool vis[1111];
int cnt;

void dfs( int u ){
	if( vis[u] ) return;
	vis[u] = ++cnt;
	rep( i, 0, adj[u].size() ) dfs( adj[u][i] );
}

int main(){
	
	int n, m, a, b, c;
	while( scanf("%d%d", &n, &m ) != EOF ){
		cnt = 0;
		rep( i, 0, n+1 ) adj[i].clear(), vis[i] = 0;
		while( m-- ){
			scanf("%d%d", &a, &b );
			adj[a].pb(b), adj[b].pb(a);
		}
		scanf("%d", &c );
		dfs(c);
		printf("%d\n", cnt );
	}
}
