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

vector<int> adj[2002];
int h[2002];

int dfs( int u, int p = -1 ){
	if( p == -1 ) h[u] = 1;
	else h[u] = h[p]+1;
	int ans = h[u];
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i];
		ans = max( ans, dfs(v, u) );
	}
	return ans;
}

int main(){
	int n, v[2002];
	while( scanf("%d", &n ) != EOF ){
		rep( i, 1, n+1 ){
			scanf("%d", &v[i] );
			if( v[i] != -1 )
				adj[v[i]].pb(i);
		}
		int ans = 0;
		rep( i, 1, n+1 ){
			if( v[i] == -1 )
				ans = max( ans, dfs(i) );
		}
		printf("%d\n", ans );
	}
}


