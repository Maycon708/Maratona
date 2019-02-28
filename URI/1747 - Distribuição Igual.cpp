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

unordered_set<int> st, vis[10010];
vector<int> adj[10010];
int v[10010];

int mdc( int a, int b ){
	while( b ){
		int c = a%b;
		a = b;
		b = c;
	}
	return a;
}

void dfs( int u, int gcd ){
	if( vis[u].count(gcd) ) return; 
	vis[u].insert(gcd);
	st.insert(gcd);
	if( gcd == 1 ) return;
	rep( i, 0, adj[u].size() ){
		int w = adj[u][i];
		dfs( w, mdc( gcd, v[w] ) );
	}
}
int main(){
	int n, m, a, b;
	while( scanf("%d%d", &n, &m ) != EOF ){
		st.clear();
		rep( i, 0, n ) vis[i].clear(), adj[i].clear(), scanf("%d", &v[i] );
		while( m-- ){
			scanf("%d%d", &a, &b );
			a--, b--;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		rep( i, 0, n ){
			dfs( i, v[i] );
		}
		printf("%d\n", int( st.size() ) );
	}	
}
