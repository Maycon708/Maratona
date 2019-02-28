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
#define N 100010

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;
typedef vector<int> VI;

VI g[N],tree[N],rg[N],bucket[N];
int sdom[N],par[N],dom[N],dsu[N],label[N];
int arr[N],rev[N],T;
//1-Based directed graph input
    
int Find(int u,int x=0){
	if( u == dsu[u] ) return x ? -1 : u;
	int v = Find( dsu[u], x+1 );
	if( v < 0 ) return u;
	if( sdom[label[dsu[u]]] < sdom[label[u]] )
		label[u] = label[dsu[u]];
	dsu[u] = v;
	return x ? v : label[u];
}

void Union( int u,int v ){
	dsu[v] = u;
}

void dfs0( int u ){
	T++; arr[u] = T; rev[T] = u;
	label[T] = T; sdom[T] = T; dsu[T] = T;
	for(int i = 0; i < g[u].size(); i++){
		int w = g[u][i];
		if( !arr[w] ) dfs0(w), par[arr[w]] = arr[u];
		rg[arr[w]].pb(arr[u]);
	}
}
ll ans;

int dfs( int u, int p ){
	int ret = 1;
	for(int i = 0; i < tree[u].size(); i++ ){
		int w = tree[u][i];
		if( w == p ) continue;
		ll x = dfs(w,u);
		if( u == 1 ) ans -= ( x * (x-1) )/2;
		else ret += x;
	}
	return ret;
}

void init( int n ){
	T = 0;
	rep( i, 0, n+1 ) 
		arr[i] = 0,	
		g[i].clear(), 
		rg[i].clear(), 
		bucket[i].clear(), 
		tree[i].clear();
}


int main(){

	ll n, m, u, v;
	while( scanf("%lld%lld", &n, &m ) != EOF ){
		init(n);
		while( m-- ){
			scanf("%lld%lld\n", &u, &v );
			g[u].pb(v);
		}
		dfs0(1);
		n = T;
		for( int i = n; i >= 1; i-- ){
			for( int j = 0; j < rg[i].size(); j++ )
				sdom[i] = min( sdom[i], sdom[Find(rg[i][j])] );
			if( i > 1 ) bucket[sdom[i]].pb(i);
			for(int j = 0; j < bucket[i].size(); j++ ){
				int w = bucket[i][j];
				int v = Find(w);
				if( sdom[v] == sdom[w] ) dom[w] = sdom[w];
				else dom[w] = v;
			}
			if( i > 1 ) Union(par[i],i);
		}
		for(int i = 2; i <= n; i++ ){
			if( dom[i] != sdom[i] )
				dom[i] = dom[dom[i]];
			tree[rev[dom[i]]].pb(rev[i]);
			tree[rev[i]].pb(rev[dom[i]]);
		}
		ans = ( n * (n-1) )/2;
		dfs(1,1);
		printf("%lld\n", ans );
	}
	return 0;
}
