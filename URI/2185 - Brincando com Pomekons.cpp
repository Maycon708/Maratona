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

const int N = 1000100;

int lazy[4*N], tree[4*N], vet[N];

void build( int no, int i, int j ){
	
	lazy[no] = -1;
	
	if( i == j ){
		tree[no] = vet[i];
		return;
	}
	
	int mid = ( i + j ) >> 1;
	int left = ( no << 1 ), right = left ^ 1;
	
	build( left, i, mid );
	build( right, mid+1, j );
	
	tree[no] = ( tree[left] ^ tree[right] );
	
}

void propagate( int no, int i, int j, int v ){
	
	lazy[no] = -1;
	
	if( i != j ){
		int left = ( no << 1 ), right = left ^ 1;
		lazy[left] = lazy[right] = v;
	}
	tree[no] = ( ( j - i + 1 )&1 ) ? v : 0;
}

void update( int no, int i, int j, int a, int b, int v ){
	
	if( lazy[no] != -1 ) propagate( no, i, j, lazy[no] );
	
	if( i > b || j < a ) return;
	
	if( i >= a && j <= b ){
		propagate( no, i, j, v );
		return;
	}
		
	int mid = ( i + j ) >> 1;
	int left = ( no << 1 ), right = left ^ 1;
	
	update( left, i, mid, a, b, v );
	update( right, mid+1, j, a, b, v );
	
	tree[no] = ( tree[left] ^ tree[right] );
}

int query( int no, int i, int j, int a, int b ){
	
	if( lazy[no] != -1 ) propagate( no, i, j, lazy[no] );
	
	if( i > b || j < a ) return 0;
	
	if( i >= a && j <= b ) return tree[no];
	
	int mid = ( i + j ) >> 1;
	int left = ( no << 1 ), right = left ^ 1;
	
	int aa = query( left, i, mid, a, b );
	int bb = query( right, mid+1, j, a, b );
	
	return aa ^ bb;
}

int main(){
	
	int n, m, a, b, c;
	while( scanf("%d%d", &n, &m ) != EOF ){
		rep( i, 0, n ) scanf("%d", &vet[i] );
		build( 1, 0, n-1 );
		while( m-- ){
			scanf("%d%d%d", &a, &b, &c );
			a--, b--;
			update( 1, 0, n-1, a, b, c );
			int ans = query( 1, 0, n-1, 0, n-1 );
			if( ans ) puts("Possivel");
			else puts("Impossivel");
		}
	}
}
