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

const int N = 100100;

int custo[N], k;
vector<int> adj[N];

inline bool cmp( int a, int b ){
	return custo[a] < custo[b];
}

void dfs( int u ){
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i];
		dfs(v);
	}
	
	if( adj[u].empty() ){
		custo[u] = 1;
		return;
	}
	
	sort( all( adj[u] ), cmp );
	int mn = ( adj[u].size() * k );
	if( mn%100 ) mn = mn/100 + 1;
	else mn = mn/100;
	
	custo[u] = 0;
	rep( i, 0, mn ){
		int v = adj[u][i];
		custo[u] += custo[v];
	}
	adj[u].clear();
}

int main(){
	int n, u;
	while( scanf("%d%d", &n, &k ) != EOF ){
		if( !n ) break;
		rep( i, 1, n+1 ){
			scanf("%d", &u );
			adj[u].pb(i);
		}
		dfs( 0 );
		printf("%d\n", custo[0] );
	}
}

