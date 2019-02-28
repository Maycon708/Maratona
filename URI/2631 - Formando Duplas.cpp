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
#define N 25000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int cmp[N], cnt;
vector<int> adj[N];

void dfs( int u ){
	if( cmp[u] != -1 ) return;
	cmp[u] = cnt;
	rep( i, 0, adj[u].size() ) dfs( adj[u][i] );
}

int main(){
	int n, m, q, u, v, l = 0;
	while( scanf("%d%d%d", &n, &m, &q ) != EOF ){
		if( l ) printf("\n");
		l = 1;
		rep( i, 0, n ) cmp[i] = -1, adj[i].clear(); cnt = 0;
		while( m-- ){
			scanf("%d%d", &u, &v );
			u--, v--;
			adj[u].pb(v); adj[v].pb(u);
		}
		while(q--){
			scanf("%d%d", &u, &v );
			u--, v--;
			dfs(u);
			cnt++;
			printf("%c\n", cmp[u] == cmp[v] ? 'S' : 'N' );
		}
	}
}
