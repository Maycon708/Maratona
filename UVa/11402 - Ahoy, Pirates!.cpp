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

const int N = 4 * 1024000; 

int tree[N], lazy[N];
string s;

void build( int no, int i, int j ){
	lazy[no] = 0;
	if( i == j ){
		tree[no] = s[i] == '1';
		return;
	}
	int l = no * 2, r = l+1, mid = (i+j)/2;
	build( l, i, mid );
	build( r, mid+1, j );
	tree[no] = tree[l] + tree[r];
}

void propagate( int no, int i, int j ){
	if( lazy[no] & 1 ) tree[no] = ( j-i+1 );
	if( lazy[no] & 2 ) tree[no] = 0;
	if( lazy[no] & 4 ) tree[no] = ( j-i+1 ) - tree[no];
	if( i != j ){
		int l = 2 * no, r = l + 1;
		if( lazy[no] == 4 ) lazy[l] ^= 4, lazy[r] ^= 4;
		else lazy[l] = lazy[r] = lazy[no];	
	}
	lazy[no] = 0;
}

int query( int no, int i, int j, int a, int b ){
	if( lazy[no] ) propagate(no, i, j);
	if( i > b || j < a ) return 0;
	if( i >= a && j <= b ) return tree[no];
	int l = no * 2, r = l+1, mid = (i+j)/2;
	int aa = query( l, i, mid, a, b );
	int bb = query( r, mid+1, j, a, b );
	return aa + bb;
}

void update( int no, int i, int j, int a, int b, int type ){
	if( lazy[no] ) propagate(no, i, j);
	if( i > b || j < a ) return;
	if( i >= a && j <= b ){
		lazy[no] = type;
		propagate( no, i, j );
		return;
	}
	int l = no * 2, r = l+1, mid = (i+j)/2;
	update( l, i, mid, a, b, type );
	update( r, mid+1, j, a, b, type );
	tree[no] = tree[l] + tree[r];
}

int main(){
	int t, a, b, q, test = 1, n, qq;
	char aux[111], op;
	scanf("%d", &t );
	while( t-- ){
		s.clear();
		scanf("%d", &a );
		rep( i, 0, a ){
			scanf("%d%s", &b, aux );
			n = strlen(aux);
			rep( j, 0, b ) rep( k, 0, n ) s.pb(aux[k]);
		}
		n = s.size()-1;
		build( 1, 0, n );
		qq = 1;
		scanf("%d", &q );
		printf("Case %d:\n", test++ );
		while( q-- ){
			scanf(" %c%d%d", &op, &a, &b );
			if( op == 'F' ) update( 1, 0, n, a, b, 1 );
			if( op == 'E' ) update( 1, 0, n, a, b, 2 );
			if( op == 'I' ) update( 1, 0, n, a, b, 4 );
			if( op == 'S' ) printf("Q%d: %d\n", qq++, query( 1, 0, n, a, b ) );
		}
				
	}
}
