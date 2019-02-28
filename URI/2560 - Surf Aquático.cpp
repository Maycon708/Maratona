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

typedef long long int ll;
typedef pair <ll, ll> ii;
typedef pair <ii, ll> iii;

int v[222222];
iii tree[4*222222];

iii C( iii a, iii b ){
	return mk( ii( min( a.F.F, b.F.F ), max( a.F.S, b.F.S ) ), a.S + b.S );
}

void build( int no, int i, int j ){
	if( i == j ){
		tree[no] = mk( ii( v[i], v[i] ), v[i] );
		return;
	}
	int mid = (i+j)/2;
	int L = 2*no, R = L+1;
	build( L, i, mid );
	build( R, mid+1, j );
	tree[no] = C( tree[L], tree[R] );
}

iii query( int no, int i, int j, int a, int b ){
	if( j < a || i > b ) return mk( ii( INF, -INF ), 0 );
	if( i >= a && j <= b ) return tree[no];
	int mid = (i+j)/2;
	int L = 2*no, R = L+1;
	iii aa = query( L, i, mid, a, b );
	iii bb = query( R, mid+1, j, a, b );
	return C( aa, bb );
}

int main(){
	
	int n, k;	
	while( scanf("%d%d", &n, &k ) != EOF ){
		rep( i, 0, n ) scanf("%d", &v[i] );
		build( 1, 0, n-1 );
		ll ans = 0;
		rep( i, 0, n-k+1 ){
			iii a = query( 1, 0, n-1, i, i+k-1 );
			ans += a.S - a.F.F - a.F.S;
		}
		printf("%lld\n", ans );
	}	
}
