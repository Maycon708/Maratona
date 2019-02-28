#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-2
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef int ll;

#define MAX 1000

int tree[MAX*4][MAX*4];

int gcd( int a, int b ){
	return max(a,b);
}

void updateY( int x, int y, int i, int j, int yy, int v, bool c ){
	if( i > yy || j < yy ) return;
	if( i == j ){
		if( c ) tree[x][y] = v;
		else tree[x][y] = gcd( tree[x<<1][y], tree[1^(x<<1)][y] );
		return;
	}
	int mid = ( i + j ) >> 1;
	int L = y << 1;
	int R = L ^ 1;
	updateY( x, L, i, mid, yy, v, c );
	updateY( x, R, mid+1, j, yy, v, c );
	tree[x][y] = gcd( tree[x][L], tree[x][R] );
}

int queryY( int x, int y, int i, int j, int a, int b ){
	if( i > b || j < a ) return 0;
	if( i >= a && j <= b ) return tree[x][y];
	int mid = ( i + j ) >> 1;
	int L = y << 1;
	int R = L ^ 1;
	int aa = queryY( x, L, i, mid, a, b );
	int bb = queryY( x, R, mid+1, j, a, b );
	return gcd( aa, bb );
}

void updateX( int x, int i, int j, int a, int b, int v ){
	if( i > a || j < a ) return;
	if( i == j ){
		updateY( x, 1, 0, MAX-1, b, v, 1 );
		return; 
	}
	int mid = ( i + j ) >> 1;
	int L = x << 1;
	int R = L ^ 1;
	updateX( L, i, mid, a, b, v );
	updateX( R, mid+1, j, a, b, v );
	tree[x][1] = gcd( tree[L][1], tree[R][1] );
	updateY( x, 1, 0, MAX-1, b, v, 0 );
}

int queryX( int x, int i, int j, int x1, int x2, int y1, int y2 ){
	if( i > x2 || j < x1 ) return 0;
	if( i >= x1 && j <= x2 ) return queryY( x, 1, 0, MAX-1, y1, y2 );
	int mid = ( i + j ) >> 1;
	int L = x << 1;
	int R = L ^ 1;
	int _a = queryX( L, i, mid, x1, x2, y1, y2 );
	int _b = queryX( R, mid+1, j, x1, x2, y1, y2 );
	return gcd( _a, _b );
}

#define N 50011

vector<int> adj[N];
int g[N], resp, X[N], Y[N];

void init( int n ){
	resp = 0;
	rep( i, 0, n+1 ){
		adj[i].clear();
		g[i] = 0;
	}
}

int dfs( int u, int p = -1 ){
	int ans = queryX( 1, 0, MAX-1, 0, X[u]-1, 0, Y[u]-1 )+1;
	resp = max( resp, ans );
	updateX( 1, 0, MAX-1, X[u], Y[u], ans );
	rep( i, 0, adj[u].size() ){
		int v = adj[u][i];
		if( v == p ) continue;
		dfs(v);
	}
	updateX( 1, 0, MAX-1, X[u], Y[u], 0 );
	return ans;
} 

int main(){
	
	int n, m, a, b;
	while( scanf("%d%d", &n, &m ) != EOF ){
		init( n );
		rep( i, 1, n+1 ){
			scanf("%d%d", &X[i], &Y[i] );
			X[i] += 401;
			Y[i] += 401;
		}
		rep( i, 0, m ){
			scanf("%d%d", &a, &b );
			adj[b].pb(a);
			g[a]++;	
		}
		rep( i, 1, n+1 ){
			if( !g[i] ){
				dfs(i);
			}
		}
		printf("%d\n", resp );
	}
}
