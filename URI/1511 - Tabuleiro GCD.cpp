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

#define MAX 2000

int tree[MAX*3][MAX*3];

int gcd( int a, int b ){
	if( a > b ) swap( a, b );
	if( !b ) return a;
	return __gcd(a, b);
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

int queryX( int x, int i, int j, int _x, int _y, int d ){
	if( i > _x+d || j < _x-d ) return 0;
	if( i >= _x-d && j <= _x+d ) return queryY( x, 1, 0, MAX-1, _y - d, _y + d );
	int mid = ( i + j ) >> 1;
	int L = x << 1;
	int R = L ^ 1;
	int _a = queryX( L, i, mid, _x, _y, d );
	int _b = queryX( R, mid+1, j, _x, _y, d );
	return gcd( _a, _b );
}

int main(){
	int n, a, b, c;
	char op[20];
	while( scanf("%d", &n ) != EOF ){
		memset( tree, 0, sizeof tree );
		rep( i, 0, n ){
			scanf("%s%d%d%d", op, &a, &b, &c );
			int x = a + b + 1000;
			int y = a - b + 1000;
			if( strcmp(op, "SET") == 0 ) updateX( 1, 0, MAX-1, x, y, c );
			else printf("%d\n", queryX( 1, 0, MAX-1, x, y, c ) );
		}
	}
}
