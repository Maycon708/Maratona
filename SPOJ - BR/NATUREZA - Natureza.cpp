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

vector<int> adj[5005];
bool vis[5005];

int dfs( int u ){
	if( vis[u] ) return 0;
	vis[u] = 1;
	int ans = 1;
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i];
		ans += dfs(v);
	}
	return ans;
}

int main(){
	int n, m;
	char s1[5005], s2[5005];
	while( scanf("%d%d", &n, &m ) != EOF && n ){
		map<string, int> mp;
		rep( i, 0, n ){
			scanf("%s", s1 );
			mp[s1] = i;
			adj[i].clear();
			vis[i] = 0;
		}
		while( m-- ){
			scanf("%s%s", s1, s2 );
			int u = mp[s1], v = mp[s2];
			adj[u].pb(v); adj[v].pb(u);
		}
		int ans = 0;
		rep( i, 0, n ) if( !vis[i] ) ans = max( ans, dfs(i) );
		printf("%d\n", ans );
	}
}
