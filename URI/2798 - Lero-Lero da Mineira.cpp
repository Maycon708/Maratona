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
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

vector<int> adj[130];
int ciclo, cor[130];

void dfs( int u ){
	ciclo |= cor[u] == -1;
	if( cor[u] ) return;
	cor[u] = -1;
	rep( i, 0, adj[u].size() ) dfs( adj[u][i] );
	cor[u] = 1;
}

void dfs2( int u ){
	if( adj[u].empty() ) printf("%c", u );
	else rep( i, 0, adj[u].size() ) dfs2( adj[u][i] );
}

int main(){
	int n, m;
	char c, s[130010];
	scanf("%d", &n );
	rep( i, 0, n ){
		scanf(" %c%s", &c, s );
		int t = strlen(s);
		if( t == 1 && s[0] == c ) continue;
		rep( i, 0, t ) adj[c].pb(s[i]);
	}
	scanf("%d", &m );
	scanf("%s", s );
	rep( i, 0, m ){
		dfs(s[i]);
		if( ciclo ){
			puts("-1");
			return 0;
		}
	}
	rep( i, 0, m ) dfs2(s[i]);
	printf("\n");
}
