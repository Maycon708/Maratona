#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define it(i, a)  for( typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

const int N = 10010;

int buracos[N], edges[N], vis[N], aux[N];
vector<ii> adj[N];
set<int> bairro[N];
map<ii, bool> usadas;

int init( int n ){
	usadas.clear();
	rep( i, 0, n ){
		adj[i].clear();
		vis[i] = 0;
		buracos[i] = 0;
		edges[i] = 0;
		bairro[i].clear();
		aux[i] = i;
	}
}

void dfs( int u, int cmp ){
	if( vis[u] ) return;
	vis[u] = 1;
	bairro[cmp].insert( u );
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i].F;
		int c = adj[u][i].S;
		if( usadas.count( ii( u, v ) ) ) continue;
		usadas[ ii( u, v ) ] = usadas[ ii( v, u ) ] = 1;
		edges[cmp]++;
		buracos[cmp] += c;
		dfs( v, cmp );
	}
}

inline bool cmp( int a, int b ){
	if( buracos[a] && !buracos[b] ) return 0;
	if( !buracos[a] && buracos[b] ) return 1;
	if( buracos[a] * edges[b] != buracos[b] * edges[a] ) 
		return buracos[a] * edges[b] < buracos[b] * edges[a];
	return *( --bairro[a].end() ) > *( --bairro[b].end() );
}

int main(){
	int n, m, u, v, c;
	while( scanf("%d%d", &n, &m ) != EOF ){
		init( n+1 );
		while( m-- ){
			scanf("%d%d%d", &u, &v, &c );
			u--, v--;
			adj[u].pb( ii( v, c ) );
			adj[v].pb( ii( u, c ) );
		}
		int cnt = 0;
		rep( i, 0, n ){
			if( !vis[i] ) dfs( i, cnt++ );
		}
		sort( aux, aux+cnt, cmp );
		int b = aux[0];
		printf("%d\n", *( -- bairro[b].end() ) +1 );
	}	
}
