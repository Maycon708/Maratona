#include <bits/stdc++.h>

#define INF 1LL << 62
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

typedef long long int ll;
typedef pair <ll, ll> ii;

#define N 20020

ll pai[N], cont[N], ans[N], g[N];
vector<int> adj[N];

void dfs( int u, int p ){
	cont[u] = 1, ans[u] = 0;
	int check = 0;
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i];
		if( v == p ) continue;
		check++;
		dfs( v, u );
		ans[u] += ( cont[u]-1 ) * ( cont[v] );
		cont[u] += ( cont[v] );
	}
}

int main(){
	int t, n, u, v, test = 1;
	scanf("%d", &t );
	while( t-- ){
		scanf("%d", &n );
		rep( i, 0, N ){
			adj[i].clear();
			g[i] = 0;
		}
		rep( i, 1, n ){
			scanf("%d%d", &u, &v );
			adj[u].pb(v);
			adj[v].pb(u);
			g[u]++, g[v]++;
		}
		rep( i, 1, n+1 ){
			if( g[i] == 1 ){
				dfs( i, -1 );
				break;
			}
		}
		ll resp = 0;
		rep( i, 1, n+1 ){
			if( g[i] == 1 ) continue;
			resp = max( resp, ans[i] + ( n - cont[i] ) * ( cont[i] - 1 ) );
		}
		printf("Case #%d: %lld\n", test++, resp );
	}
}
