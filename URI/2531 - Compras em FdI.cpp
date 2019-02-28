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

#define N 100010

ii tree[4*N];
int v[N];

#define gc getchar//_unlocked

void scan( int &x ){
    register int c = gc(), aux = 0;
    x = 0;
    for( ; ( c < 48 || c > 57 ) && c != EOF; c = gc() ) if( c == '-' ) aux = 1;
    for( ; c > 47 && c < 58; c = gc() ){ x = (x << 1 ) + ( x << 3) + c - 48; }
    if( aux ) x *= -1;
}


void build( int no, int i, int j ){
	if( i > j ) return;
	if( i == j ){
		tree[no] = ii( v[i], v[i] );
		return;
	}
	int mid = ( i+j )/2;
	int L = 2*no, R = L+1;
	build( L, i, mid );
	build( R, mid+1, j );
	tree[no] = ii( min( tree[L].F, tree[R].F ), max( tree[L].S, tree[R].S ) );
}


void update( int no, int i, int j, int a, int val ){
	if( a < i || a > j || i > j) return;
	if( i == j && i == a ){
		tree[no] = ii( val, val );
		return;
	}
	int mid = ( i+j )/2;
	int L = 2*no, R = L+1;
	update( L, i, mid, a, val );
	update( R, mid+1, j, a, val );
	tree[no] = ii( min( tree[L].F, tree[R].F ), max( tree[L].S, tree[R].S ) );
}


ii query( int no, int i, int j, int a, int b ){
	if( i > b || j < a || i > j ) return ii( INF, -INF );
	if( i >= a && j <= b ) return tree[no];
	int mid = ( i+j )/2;
	int L = 2*no, R = L+1;
	ii aa = query( L, i, mid, a, b );
	ii bb = query( R, mid+1, j, a, b );
	return ii( min( aa.F, bb.F ), max( aa.S, bb.S ) );
}

int main(){
	int n, q, op, a, b;
	while( 42 ){
		scan(n);
		if( !n ) break;
		rep( i, 0, n ) scan(v[i]);
		build( 1, 0, n-1 );
		scanf("%d", &q );
		while( q-- ){
			scan(op);
			scan(a);
			scan(b);
			a--;
			if( op == 1 ) update( 1, 0, n-1, a, b );
			else{
				b--;
				ii aux = query( 1, 0, n-1, a, b );
				printf("%d\n", aux.S - aux.F );
			}
		}
	}
}

