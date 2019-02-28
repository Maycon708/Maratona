#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int tree[400400];

void update( int no, int i, int j, int a, int v ){
	if( i == j ){
		tree[no] = v;
		return;
	}
	int L = 2*no, R = L+1, mid = (i+j)/2;
	if( mid >= a ) update( L, i, mid, a, v );
	else update( R, mid+1, j, a, v );
	tree[no] = max( tree[L], tree[R] );
}

int query( int no, int i, int j, int a, int b ){
	if( i > b || j < a ) return 0;
	if( i >= a && j <= b ) return tree[no];
	int L = 2*no, R = L+1, mid = (i+j)/2;
	int aa = query( L, i, mid, a, b );
	int bb = query( R, mid+1, j, a, b );
	return max( aa, bb );
}

int main(){
	int n, v[100100], L[100100];
	scanf("%d", &n );
	rep( i, 0, n ) scanf("%d", &v[i] );
	L[0] = -1;
	int ans = 0;
	rep( i, 1, n ){
		L[i] = i-1;
		while( L[i] >= 0 && v[i] > v[L[i]] ) L[i] = L[L[i]];
		if( L[i] != -1 ){
			int aux = query( 1, 0, n-1, L[i]+1, i-1 );
			ans = max( ans, aux+1 );
			update( 1, 0, n-1, i, aux+1 );
		}
	}
	cout << ans << "\n";
}
