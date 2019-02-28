#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

using namespace std;

typedef long long int ll;

#define N 100100

vector<int> adj[N];
ll s[N], a[N], ans, mn[N];	

ll mmc( ll x, ll y ){
	return x/__gcd(x, y)*y;
}

void dfs( int u, int p = -1 ){
	int k = 0;
	mn[u] = 1;
	s[u] = a[u];
	for( auto v : adj[u] ){
		if( v == p ) continue;
		dfs(v, u);
		k++;
		mn[u] = mmc( mn[u], mn[v] );
		s[u] += s[v];
	}
	if( k ) mn[u] *= k;
}

void dfs2( int u, int p = -1 ){
	ll menor = 1LL << 60, k = 0;
	for( auto v : adj[u] ){
		if( v == p ) continue;
		dfs2(v, u);
		k++;
		menor = min( menor, s[v] );
	}
	if( !k ) return;
	if( mn[u] ){
		mn[u] /= k;
		menor -= menor%mn[u];
	}
	else menor = 0;
	for( auto v : adj[u] ){
		if( v == p ) continue;
		ans += ( s[v] - menor );
	}
	s[u] = menor*k;  
}

int main(){
	int n, u, v;
	scanf("%d", &n );
	rep( i, 1, n+1 ) scanf("%I64d", &a[i] );	
	rep( i, 1, n ){
		scanf("%d%d", &u, &v );
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1);
	dfs2(1);
	cout << ans << "\n";
}

