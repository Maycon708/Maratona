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

int adj[10][10];

int dfs( int u ){
	int ans = 0;
	rep( i, 0, 10 ){
		if( !adj[u][i] ) continue;
		adj[u][i] = adj[i][u] = 0;
		ans = max( ans, 1 + dfs(i) );
		adj[u][i] = adj[i][u] = 1;
	}
	return ans;
}

int main(){
	int n, a, b;
	while( scanf("%d", &n ) != EOF ){
		memset( adj, 0, sizeof adj );
		while( n-- ){
			scanf("%d%d", &a, &b );
			adj[a][b] = adj[b][a] = 1;
		}
		int ans = 0;
		rep( i, 0, 10 ) ans = max( ans, dfs(i) );
		printf("%d\n", ans );
	}	
}
