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
#define N 100100
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

vector<int> adj[N];
int vis[N][2];
bool win, draw;
int cor[N];

int dfs( int u, int p ){
	if( adj[u].empty() && p == 0 ){
		win = 1; 
		vis[u][p] = 2;
		return vis[u][p];
	}
	for( auto v : adj[u] ){
		if( vis[v][p^1] == 0 ){
			if( !vis[v][p^1] ) vis[v][p^1] = 1;
			int x = dfs(v, p^1);
			if( x > 1 && vis[u][p]  <= 1 ) vis[u][p] = x+1;
		}
	}
	return vis[u][p];	
}

void dfs2( int u ){
	for( auto v : adj[u] ){
		if( cor[v] == 0 ){
			cor[v] = 1;
			dfs2(v);
		}
		else if( cor[v] == 1 ) draw = 1;
	}
	cor[u] = 2;
}

void back( int u, int p ){
	for( auto v : adj[u] ){
		if( vis[v][p^1] == vis[u][p]-1 ){
			printf(" %d", v );
			back( v, p^1 );
			break;
		}
	}
}

int main(){
	int n, m, c, u, s;
	while( scanf("%d%d", &n, &m ) != EOF ){
		for( int i = 1; i <= n; ++i ){
			scanf("%d", &c );
			while( c-- ){
				scanf("%d", &u );
				adj[i].pb(u);
			}
		}
		scanf("%d", &s );
		win = draw = 0;
		dfs( s, 1 );
		dfs2( s );
		if( win ){
			puts("Win");
			printf("%d", s );
			back(s, 1);
			printf("\n");
		}
		else if( draw ) puts("Draw");
		else puts("Lose");
		rep( i, 0, n+1 ){
			adj[i].clear();
			vis[i][0] = vis[i][1] = 0;
			cor[i] = 0;
		}
		
	}
}
