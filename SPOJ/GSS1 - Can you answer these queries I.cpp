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

struct node{
	ll pref, suff, best, sum;
	node(){};
	node( ll a ){
		pref = suff = best = sum = a;
	}
} tree[200000];

ll v[200000];

node cmp( node a, node b ){
	node c;
	c.sum = a.sum + b.sum;
	c.pref = max( a.pref, a.sum + b.pref );
	c.suff = max( b.suff, b.sum + a.suff );
	c.best = max( a.best, max( b.best, a.suff + b.pref ) );
	return c;
}


void D( node a ){
	printf("P: %lld -- S: %lld -- B: %lld -- Sum: %lld\n", a.pref, a.suff, a.best, a.sum );
}

void build( int no, int i, int j ){
	if( i == j ){
		tree[no] = node(v[i]);
		return;
	}
	int l = no * 2, r = l+1, mid = (i+j)/2;
	build( l, i, mid );
	build( r, mid+1, j );
	tree[no] = cmp( tree[l], tree[r] );
}

node query( int no, int i, int j, int a, int b ){
	if( i > b || j < a ) return node(-1LL<<30);
	if( i >= a && j <= b ) return tree[no];
	int l = no * 2, r = l+1, mid = (i+j)/2;
	node aa = query( l, i, mid, a, b );
	node bb = query( r, mid+1, j, a, b );
	return cmp( aa, bb );
}

int main(){
	int n, a, b, q;
	while( scanf("%d", &n ) != EOF ){
		rep( i, 0, n ) scanf("%lld", &v[i]);
		build(1, 0, n-1);
		scanf("%d", &q );
		while( q-- ){
			scanf("%d%d", &a, &b );
			if(a) --a;
			if(b) --b;
			node ans = query( 1, 0, n-1, a, b );
			printf("%lld\n", ans.best );
		}
	}
}

