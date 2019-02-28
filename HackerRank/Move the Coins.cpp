#include <bits/stdc++.h>

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

#define N 50505

vector<int> adj[N];
int b[N], odd[N], even[N], h[N], pai[N][22];

int LCA(int a, int b){
	if(h[a]<h[b]) swap(a, b);
	
	for(int i=21; i>=0; i--){
		if(pai[a][i]==0) continue;
		if(h[pai[a][i]] >= h[b])
			a=pai[a][i];
	}
	
	if(a==b) return a;
	
	for(int i=21; i>=0; i--){
		if(pai[a][i]!=pai[b][i])
			a=pai[a][i], b=pai[b][i];
	}
	
	return pai[a][0];
	
}

void dfs( int u, int p = -1, int cnt = 0 ){
	h[u] = cnt;
	if( h[u]&1 ) odd[u] = b[u], even[u] = 0;
	else even[u] = b[u], odd[u] = 0;
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i];
		if( v == p ) continue;
		pai[v][0] = u;
		rep( j, 1, 22 ) pai[v][j] = pai[pai[v][j-1]][j-1];
		dfs( v, u, cnt+1 );
		even[u] ^= even[v];
		odd[u] ^= odd[v];
	}
}

int main(){
	
	int n, u, v, q;
	scanf("%d", &n );
	rep( i, 1, n+1 ) scanf("%d", &b[i] );
	rep( i, 1 , n ){
		scanf("%d%d", &u, &v );
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1);
	ll sum = odd[1];
	scanf("%d", &q );
	while( q-- ){
		scanf("%d%d", &u, &v );
		int x = LCA( u, v );
		if( x == u ) puts("INVALID");
		else if( ( h[u]&1 ) == ( (h[v]+1)&1 ) ) printf("%s\n", odd[1] ?  "YES" : "NO" );
		else printf("%s\n", ( odd[1] ^ even[u] ^ odd[u] ) ?  "YES" : "NO" );
	}
	
	return 0;
}

