#include <bits/stdc++.h>

#define INF 1LL << 60
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define MAX 100100
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

struct node{
	ii pref, suff, sum, best;
	
	node(){};
	node( ll a ){
		pref = suff = sum = best = ii( a, 1 );
	}
};

node tree[MAX*4];
ll v[MAX];

ii sum( ii a, ii b ){
	return ii (a.F+b.F, a.S+b.S);
}

node best( node a, node b ){
	node ans;
	ans.sum  = sum(a.sum, b.sum);
	ans.pref = max( a.pref, sum(a.sum, b.pref) );
	ans.suff = max( b.suff, sum(b.sum, a.suff) );
	ans.best = max( a.best, max( b.best, sum( a.suff, b.pref ) ));
	return ans;
}

void build( int no, int i, int j ){
	if( i == j ){
		tree[no] = node(v[i]);
		return;
	}
	int mid = (i+j)/2;
	int l = 2 * no;
	int r = l + 1;
	build( l, i, mid );
	build( r, mid+1, j );
	tree[no] = best( tree[l], tree[r] );
}

node query( int no, int i, int j, int a, int b ){
	if( i >= a && j <= b ) return tree[no];
	int mid = (i+j)/2;
	int l = 2 * no;
	int r = l + 1;
	if( b < mid+1 )
		return query( l, i, mid, a, b );
	if( a > mid )
		return query( r, mid+1, j, a, b );
	node aa = query( l, i, mid, a, b );
	node bb = query( r, mid+1, j, a, b );
	return best( aa, bb );
}

int main(){
	int t, n, q, a, b;
	while( scanf("%d", &t ) != EOF ){
		while( t-- ){
			scanf("%d", &n );
			rep( i, 0, n ) scanf("%lld", &v[i] );
			build( 1, 0, n-1 );
			scanf("%d", &q );
			while( q-- ){
				scanf("%d%d", &a, &b );
				if( a > b ) swap(a, b);
				a--, b--;
				node ans = query( 1, 0, n-1, a, b );
				printf("%lld %lld\n", ans.best.F, ans.best.S );
			}
		}
	}
}
