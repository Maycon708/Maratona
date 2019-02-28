#include <bits/stdc++.h>

#define pb push_back
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define N 1000100

using namespace std;

typedef long long int ll;

ll sz[N], st[N], ft[N], ver[N*2], maior[N], ans[N], cor[N], t, cnt[N];
vector<int> adj[N];

void getSizes( int u, int p ){
	sz[u] = 1;
	ver[t] = u;
	st[u] = t++;
	for( auto v : adj[u] ){
		if( v == p ) continue;
		getSizes(v, u);
		sz[u] += sz[v];
	}
	ft[u] = t++;
}

void add( int x, ll &m, ll &a ){
	cnt[x]++;
	if( cnt[x] > m ) a = x, m = cnt[x];
	else if( cnt[x] == m ) a += x;
}

void dfs( int u, int p, int keep ){
	ll big = -1, mx = -1;
	for( auto v : adj[u] ){
		if( v != p && sz[v] > mx ) big = v, mx = sz[v];
	}
	
	for( auto v: adj[u] ){
		if( v != p && v != big ) dfs( v, u, 0 );
	} 
	if( big != -1 ){
		dfs( big, u, 1 );
		ans[u] = ans[big];
		maior[u] = maior[big];
	}
	
	add( cor[u], maior[u], ans[u] );
	
	
	for( auto v : adj[u] ){
		if( v == p || v == big ) continue;
		for( int i = st[v]; i < ft[v] ; i++ ){
			if( !ver[i] ) continue;
			int x = cor[ ver[i] ];
			if( x ) add( x, maior[u], ans[u] );
		}
	} 
	
	if( !keep ){
		for( int i = st[u]; i < ft[u] ; i++ ){
			if( !ver[i] ) continue;
			int x = cor[ ver[i] ];
			cnt[x]--;
		}
	} 
	
	
}

int main(){
	int n, a , b;
	scanf("%d", &n );
	rep( i, 1,  n+1 ){
		scanf("%d", &cor[i] );
	}
	rep( i, 1, n ){
		scanf("%d%d", &a, &b );
		adj[a].pb(b);
		adj[b].pb(a);
	}
	getSizes(1, -1);
	dfs(1, -1, 1 );
	rep( i, 1, n+1 ){
		printf("%lld%s", ans[i], i==n? "\n":" ");
	}
}
