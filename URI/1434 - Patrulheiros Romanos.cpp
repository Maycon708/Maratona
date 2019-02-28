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

int n, I[1010], t;
vector<ii> adj[1010];

int solve( int u ){
	int ans = 0, tt = t;
	for( int i = t; i >= 0; i-- ){
		if( i == tt ){
			int aux= -1, id = -1, c;
			for( int j = adj[u].size(); j > 0; j-- ){
				int v = adj[u][j-1].F;
				if( I[v] >= aux ) aux = I[v], id = v, c = adj[u][j-1].S;
			}
			I[u] = 0;
			u = id;
			tt -= c;
		}
		for( int j = n; j > 0; j-- ) ans += I[j], I[j]++;
	}
	return ans;
}

int main(){
	int m, d, a, b, c;
	while( 42 ){
		scanf("%d%d%d%d", &n, &m, &t, &d );
		if( !n ) break;
		for( int i = n; i >= 0; i-- ) adj[i].clear(), I[i] = 0;
		for( int i = m; i > 0; i-- ){
			scanf("%d%d%d", &a, &b, &c );
			adj[a].pb( ii( b, c ) );
			adj[b].pb( ii( a, c ) );
		}
		printf("%d\n", solve(d) );
	}
}

