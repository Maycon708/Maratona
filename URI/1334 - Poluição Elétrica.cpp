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

const int N = 2e4;

int cnt, cmp[N], k, op[N], dist[N][2], g[N], v[N], ck[N];
bool vis[N][2];
vector<ii> adj[N];

void dfs( int u, int d, int o ){
	if( vis[u][o] ) return;
	vis[u][o] = 1;
	cmp[u] = cnt;	// Qual componente o vertice esta
	dist[u][o] = d;	// Constante do vertice
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i].F;
		if( u == v ) continue;
		int dv = adj[u][i].S - d;
		dfs( v, dv, o^1 );
	}
}

void dfs2( int u, int d ){
	if( ck[u] ) return;
	ck[u] = 1;
	v[u] = d;
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i].F;
		int dv = adj[u][i].S - d;
		dfs2( v, dv );
	}
}

int value( int a ){
	if( ck[a] ) return v[a];
	if( vis[a][0] && vis[a][1] ) 
		return ( dist[a][0] + dist[a][1] )/2;
	return 1 << 30;
} 	 		

int main(){
	int m, q, a, b, c, t = 0;
//	freopen( "in.in", "r", stdin );
//	freopen( "out.txt", "w", stdout );
	while(42){
		scanf("%d%d", &m, &q );
		if( !m && !q ) break;
		map<int, int> mp;
		cnt = k  = 0;
		
		while( m-- ){
			scanf("%d%d%d", &a, &b, &c );
			if( !mp.count(a) ) mp[a] = k++;
			if( !mp.count(b) ) mp[b] = k++;
			a = mp[a], b = mp[b];
			if( a == b ){
				v[a] = c, ck[a] = 1;
			}
			adj[a].pb( ii( b, c ) ),
			adj[b].pb( ii( a, c ) );
		}
		
		rep( i, 0, k ){
			if( ck[i] ) ck[i] = 0, dfs2( i, v[i] );
		}
		rep( i, 0, k ){
			if( !ck[i] && !cmp[i] ){ 
				cnt++;
				dfs( i, 0, 0 ); 
			}
		}

		while( q-- ){
			t++;
			scanf("%d%d", &a, &b );
			if( !mp.count(a) || !mp.count(b)  ){
				printf("*\n");
				continue;
			}
			a = mp[a], b = mp[b];
			if( cmp[a] != cmp[b] ){
				if( value(a) != ( 1 << 30 ) && value(b) != ( 1 << 30 ) )
					printf("%d\n", value(a) + value(b) );
				else printf("*\n");
				continue;
			}
			if( a == b ){
//				if( t == 93033 ) debug2( ck[a], v[a] )
				if( value(a) != ( 1 << 30 ) ) printf("%d\n", value(a) );
				else printf("*\n");
				continue;
			}
			
			int resp = 0;
			if( ck[a] && ck[b] ) resp = v[a] + v[b];
			else if( vis[a][1] && vis[b][0] ) 
				resp = dist[b][0] + dist[a][1];
			else if( vis[a][0] && vis[b][1] )
				resp = dist[a][0] + dist[b][1];
			else{
				printf("*\n");
				continue;
			}
			printf("%d\n", resp );
		}
		printf("-\n");
		t++;
		rep( i, 0, k ) adj[i].clear(), vis[i][0] = vis[i][1] = cmp[i] = ck[i] = 0;
	} 
}

