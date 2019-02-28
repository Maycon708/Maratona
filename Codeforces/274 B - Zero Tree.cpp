#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

#define N 1000100

vector<int> adj[N];
ll val[N], add[N], sub[N];

void dfs( int u, int p = -1){
	ll &mx = add[u], &mn = sub[u];
	for( auto v : adj[u] ){
		if( v == p ) continue;
		dfs(v, u);
		mx = max( mx, add[v] );
		mn = max( mn, sub[v] );
	}
	val[u] += mx - mn;
	
	if( val[u] > 0 ) sub[u] += val[u];
	else add[u] -= val[u];
}


int main(){
	int n, a, b;
	scanf("%d", &n );
	rep( i, 1, n ){
		scanf("%d%d", &a, &b );
		adj[a].pb(b);
		adj[b].pb(a);
	}
	rep( i, 1, n+1 ) scanf("%I64d", &val[i] );
	dfs(1);
	cout << sub[1] + add[1] << "\n";
}

