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

vector<ii> adj[1010];
int cost[1010][1010], n;

void dijkstra(){
	int cnt = 0;
	for( int u = 1; u <= n; u++ ) cost[0][u] = 0;
	for( int k = 0; k < n; k++ ){
		for( int u = 1; u <= n; u++ ){
			if( cost[k][u] == INF ) continue;
			for( int i = 0; i < adj[u].size(); i++ ){
				cnt++;
				int v = adj[u][i].F;
				int d_u_v = adj[u][i].S;
				cost[k+1][v] = min( cost[k+1][v], cost[k][u] + d_u_v );
			}
		}		
	}
}

int main(){
	int m, u, v, c;
	
	int t = 1;
	while( scanf("%d%d", &n, &m ) != EOF ){
		memset( cost, INF, sizeof cost );
		rep( i, 0, m ){
			scanf("%d%d%d", &u, &v, &c );
			adj[u].pb(ii(v, c) );
		}
		dijkstra();
		double ans = INF;
		bool aa = 1;
		rep( i, 1, n+1 ){
			double aux = 0;
			rep( j, 0, n ){
				if( cost[j][i] >= INF ) continue;
				aa = 0;
				aux = max( aux, double( cost[n][i] - cost[j][i] )/ double(n-j) );
			}
			ans = min( ans, aux );
			adj[i].clear();
		}
		if( aa ) puts("-1");
		else printf("%.3f\n", ans );
//t++;
	}
}

