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

const int N = 1e5+10;

vector<int> adj[N];
vector<ii> resp;
bool ok;

bool dfs( int u, int last ){
	bool used = 0;
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i];
		if( v == last ) continue;
		bool a = dfs( v, u );
		if( !a ){
			if( used ) ok = 0;
			used = 1;
			int a = min( u, v ), b = max( u, v );
			resp.pb( ii( a, b ) );
		}
	}
	return used;
}

int main(){
	int n, u, v;
	while( scanf("%d", &n ) != EOF ){
		resp.clear(); ok = 1;
		rep( i, 0, n+1 ) adj[i].clear();
		
		rep( i, 1, n ){
			scanf("%d%d", &u, &v );
			adj[u].pb(v);
			adj[v].pb(u);
		}
		dfs( 1, 1 );
		if( ok ){
			sort( all( resp ) );
			printf("Y\n");
			rep( i, 0, resp.size() ){
				printf("%d %d\n", resp[i].F, resp[i].S );
			}
		}
		else printf("N\n");
		
	}
}

