#include<bits/stdc++.h>

using namespace std;

const int N = 101010;
const int M = 18;
int n;
set<int>g[N];

int subSize[N], sz;

int lca[N][M], h[N];

void dfs( int x, int ult ){
	set<int>:: iterator it;
	lca[x][0] = ult;
	for( int i = 1; i < M; ++i ) lca[x][i] = lca[lca[x][i-1]][i-1];	
	for( it = g[x].begin(); it != g[x].end(); it++ ){
		int v = *it;
		if( v == ult ) continue;
		h[v] = h[x]+1;
		dfs( v, x );
	}
}

int getLca( int a, int b ){
	if( h[a] < h[b] ) swap( a, b );
	int d = h[a] - h[b];
	for( int i = M-1; i >= 0; --i )
		if( ( d >> i ) & 1 ) a = lca[a][i];
	if( a == b ) return a;
	for( int i = M-1; i >= 0; --i )
		if( lca[a][i] != lca[b][i] ) a = lca[a][i], b = lca[b][i];
	return lca[a][0];
}

int getDist( int a, int b ){
	return h[a] + h[b] - 2* h[ getLca( a, b ) ];
}


void dfs0( int x, int ult ){
	set<int>:: iterator it;
	subSize[x] = 1;
	sz++;
	for( it = g[x].begin(); it != g[x].end(); it++ ){
		int v = *it;
		if( v == ult ) continue;
		dfs0( v, x );
		subSize[x] += subSize[v];
	}
}

int dfs1( int x, int ult ){
	set<int>:: iterator it;
	for( it = g[x].begin(); it != g[x].end(); it++ ){
		int v = *it;
		if( v == ult ) continue;
		if( subSize[v] * 2 >= sz ) return dfs1( v, x );
	}
	return x;
}

int pai[N];

inline void Centroid( int x, int lstCen ){
	set<int>:: iterator it;
	sz = 0;
	dfs0( x, x );
	int centroid = dfs1( x, x );
	if( x == lstCen )  pai[centroid] = centroid;
	else pai[centroid] = lstCen;
	for( it = g[centroid].begin(); it != g[centroid].end(); it++ ){
		int v = *it;
		g[v].erase( g[v].find(centroid) );
		Centroid( v, centroid );
	}
	g[centroid].clear();
}

int e[N];
multiset<int>minDist[N];

void update( int x ){
	e[x] ^= 1;
	if( e[x] ){
		int u = x;
		while( 1 ){
			minDist[u].insert( getDist( x, u ) );
			if( pai[u] == u ) break;
			u = pai[u];
		}
	}
	else{
		int u = x;
		while( 1 ){
			minDist[u].erase( minDist[u].find( getDist( x, u ) ) );
			if( pai[u] == u ) break;
			u = pai[u];
		}
	}
}

int query( int x ){
	int resp = 0x3f3f3f;
	int u = x;
	while( 1 ){
		int d1 = getDist( x, u ), d2 = 0x3f3f3f;
		if( int( minDist[u].size() ) != 0 )
			d2 = *minDist[u].begin();
		resp = min( resp,  d1 + d2 );
		if( u == pai[u] ) break;
		u = pai[u];
	}
	if( resp == 0x3f3f3f ) return -1;
	return resp;	
}

int main(){
	int a, b;
	while( scanf("%d", &n ) != EOF ){
		for( int i = 0; i < n-1; i++ ){
			scanf("%d%d", &a, &b );
			g[a].insert(b);
			g[b].insert(a);
		}
		dfs( 1, 1 );
		Centroid( 1, 1 );
		int q; 
		scanf("%d", &q );
		while( q-- ){
			int op, x;
			scanf("%d%d", &op, &x );
			if( !op ) update(x);
			else printf("%d\n", query(x) );
		}
		
	}
}
