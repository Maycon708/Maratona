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

ii tree[4*MAXV];
int lazy[4*MAXV];
int v[MAXV], N;

ii C( ii a, ii b ){
	if( a.F != b.F ) return ( a.F > b.F ) ? a : b;
	return ( a.S < b.S ) ? a : b;
}

void build( int no, int i, int j ){
	lazy[no] = 0;
	if( i == j ){
		tree[no] = ii( v[i], i );
		return;
	}
	int left = no << 1, right = left^1;
    int mid = (i+j)/2;
	build( left, i, mid );
	build( right, mid+1, j );
	tree[no] = C( tree[left], tree[right] );
}

void propagate( int no, int i, int j, int v ){
	
	int left = no << 1, right = left^1;
	
	tree[no].F = v + tree[no].F;
	
	if( i != j ) lazy[left] += v, lazy[right] += v;
	lazy[no] = 0;
}

void update( int no, int i, int j, int a, int b, int v ){
	
	if( lazy[no] ) propagate( no, i, j, lazy[no] );
	
	int left = no << 1, right = left^1;
    int mid = (i+j)/2;
	
	if( j < a || i > b ) return;
	
	if( i >= a && j <= b ){
		propagate( no, i, j, v );
        return;
    }

    update( left, i, mid, a, b, v );
    update( right, mid+1, j, a, b, v );

    tree[no] = C( tree[left], tree[right] );
}


ii query( int no, int i, int j, int a, int b ){
	
	if( lazy[no] ) propagate( no, i, j, lazy[no] );
	
	if( j < a || i > b ) return ii(-INF, i );
	if( i >= a && j <= b ) return tree[no];

	int left = no << 1, right = left^1;
	int mid = (i+j)/2;

    if( i == j ){
        return tree[no];
    }

    ii A = query( left, i, mid, a, b );
    ii B = query( right, mid+1, j, a , b );
	return C( A, B );
}

int main(){
	int n, m, w, a, b;
	char op;
	while( scanf("%d%d", &n, &m ) != EOF ){
		rep( i, 0, n ) scanf("%d", &v[i] );
		
		build( 1, 0, n-1 );
		
		while( m-- ){
			scanf(" %c%d%d", &op, &a, &b );
			a--, b--;
			if( op == 'C' ) printf("%d\n", query( 1, 0, n-1, a, b ).S+1 );
			else{
				scanf("%d", &w );
				update( 1, 0, n-1, a, b, w );
			}
		}
	}
}
