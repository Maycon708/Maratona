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

const int N = 1001;
int pd[N][N];
vector <int> adj[N];

int solve( int u, int v ){
	if( u == v ) return 0;
	if( u == 1 || v == 1 ) return 1;
	if( pd[u][v] != -1 ) return pd[u][v];
	
	bool ans = 0;
	rep( i, 0, adj[v].size() ){
		int a = u, b = adj[v][i];
		if( a > b ) swap( a, b );
		ans |= solve( a, b );
	}
	return pd[u][v] = ans;
}

void init( int n ){
	n++;
	rep( i, 0, n ){
		adj[i].clear();
		rep( j, 0, n ) pd[i][j] = -1;
	}
}

int main(){
	int n, m, u, v;
	while( scanf("%d%d", &n, &m ) != EOF ){
		init(n);
		while( m-- ){
			scanf("%d%d", &u, &v );
			if( u > v ) swap( u, v );
			adj[v].pb(u);
		}
		int cnt = 0;
		rep( i, 1, n+1 ){
			rep( j, i+1, n+1 ){
				cnt += solve( i, j );
			}
		}
		printf("%d\n", cnt );
	}
}

