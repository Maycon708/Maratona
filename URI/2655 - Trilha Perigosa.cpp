#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl;
#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 150000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);
typedef long long int ll;

using namespace std;

typedef pair <ll, ll> ii;

ll tree[4*N], v[N];

void build( int no, int i, int j ){
	if( i == j ){
		tree[no] = v[i];
		return;
	}
	int l = 2 * no, r = l + 1, mid = (i+j)/2;
	
	build( l, i, mid );
	build( r, mid+1, j );

	tree[no] = tree[l] | tree[r];
}

void update(int no, int i, int j, int p, ll v){
	if( i > p || j < p ) return; 
	if( i == p && j == p ){
		tree[no] = v;
		return;
	}
	int l = 2 * no, r = l + 1, mid = (i+j)/2;
	
	update( l, i, mid, p, v );
	update( r, mid+1, j, p, v );

	tree[no] = tree[l] | tree[r];
}

ll query(int no, int i, int j, int a, int b){
	if( i > b || j < a ) return 0; 
	if( i >= a && j <= b ) return tree[no];
	
	int l = 2 * no, r = l + 1, mid = (i+j)/2;
	
	ll aa = query( l, i, mid, a, b );
	ll bb = query( r, mid+1, j, a, b );

	return aa | bb;
}

int count( ll n ){
	int cnt = 0;
	for( int i = 0; i < 60; ++i ) if( n & (1LL << i) ) cnt++;
	return cnt;
}

map<int,int> mp;
int cnt;

int M( int n ){
	if( mp.count(n) ) return mp[n];
	return mp[n] = cnt++;
}

int main(){
	
	int n, m, q, op, a, b;
	
	while( scanf("%d%d%d", &n, &q, &m ) != EOF ){
		mp.clear(), cnt = 0;
		rep( i, 1, n+1 ) scanf("%lld", &v[i] ), v[i] = 1LL << M(v[i]);
		build( 1, 1, n );
		while( q-- ){
			scanf("%d%d%d", &op, &a, &b );
			if( op == 1 ) printf("%d\n", count( query( 1, 1, n, a, b ) ) );
			else update( 1, 1, n, a, 1LL << M(b) );
		}	
	}
}
