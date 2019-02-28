#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define val first
#define op  second

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

ii seg[1<<18];
int v[1<<18];

void join( ii &p, ii a, ii b ){
	p.op = a.op^1;
	if( !p.op ) p.val = a.val | b.val;
	else p.val = a.val ^ b.val;
}

void build( int no, int i, int j ){
	if( i == j ){
		seg[no].val = v[i-1];
		seg[no].op = 1;
		return;
	}
	int L = 2*no, R = L+1, mid = (i+j)/2;
	build( L, i, mid );
	build( R, mid+1, j );
	join( seg[no], seg[L], seg[R] );
}

void update( int no, int i, int j, int pos, int valor ){
	if( i == j ){
		seg[no].val = valor;
		seg[no].op = 1;
		return;
	}
	int L = 2*no, R = L+1, mid = (i+j)/2;
	if( pos <= mid ) update( L, i, mid, pos, valor );
	else update( R, mid+1, j, pos, valor );
	join( seg[no], seg[L], seg[R] );
}

int main(){
	int n, q, pos, valor;
	scanf("%d%d", &n, &q );
	rep( i, 0, 1<<n ) scanf("%d", &v[i] );
	build( 1, 1, 1<<n );
	while( q-- ){
		scanf("%d%d", &pos, &valor );
		update( 1, 1, 1<<n, pos, valor );
		printf("%d\n", seg[1].val );
	}
}
