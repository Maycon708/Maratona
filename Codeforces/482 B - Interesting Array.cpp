#include <bits/stdc++.h>

#define INF 1LL << 62
#define rep(i, a, b) for(ll i = ll(a); i < ll(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 200000

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

struct S{
	ll i, v, op;
	S(){};
	S( ll a, ll b, ll c ){
		i = a, op = b, v = c;
	}
};

bool cmp( S a, S b ){
	if( a.i != b.i ) return a.i < b.i;
	if( a.op != b.op ) return a.op < b.op;
	return a.v < b.v;
}

ll tree[4*N], l[N], r[N], w[N], ans[N];

void build( ll no, ll i, ll j ){
	if( i == j ){
		tree[no] = ans[i];
		return;
	}
	ll l = 2 * no, r = l + 1, mid = ( i + j )/2;
	build( l, i, mid );
	build( r, mid+1, j );
	tree[no] = tree[l] & tree[r]; 
}

ll query( ll no, ll i, ll j, ll a, ll b ){
	if( i >= a && j <= b ) return tree[no];
	ll l = 2 * no, r = l + 1, mid = ( i + j )/2;
	if( mid < a ) return query( r, mid+1, j, a, b );
	if( mid+1 > b ) return query( l, i, mid, a, b );
	ll aa = query( l, i, mid, a, b );
	ll bb = query( r, mid+1, j, a, b );
	return aa & bb;
}

ll cont[40];

ll add( ll n ){
	ll ans = 0;
	for( ll i = 1, j = 0; j <= 30; i <<= 1, j++ ){
		if( i&n ) cont[j]++;
		if( cont[j] ) ans += i;
	}
	return ans;
}

ll remove( ll n ){
	ll ans = 0;
	for( ll i = 1, j = 0; j <= 30; i <<= 1, j++ ){
		if( i&n ) cont[j]--;
		if( cont[j] ) ans += i;
	}
	return ans;
}

int main(){
	ll n, k;
	while( scanf("%lld%lld", &n, &k ) != EOF ){
		vector<S> v;
		memset( cont, 0, sizeof cont );
		rep( i, 1, k+1 ){
			scanf("%lld%lld%lld", &l[i], &r[i], &w[i] );
			v.pb( S( l[i], 0, w[i] ) );
			v.pb( S( r[i], 1, w[i] ) );
		}
		ll j = 1, at = 0;
		sort( all(v), cmp );
		rep( i, 0, v.size() ){
			while( j < v[i].i ) ans[j++] = at;
			if( v[i].op == 0 ) at = add(v[i].v);
			else{
				if( j == v[i].i ) ans[j++] = at;
				at = remove(v[i].v);
			}
		}
		build( 1, 1, n );
		bool aux = 1;
		rep( i, 1, k+1 ){
			if( query( 1, 1, n, l[i], r[i] ) != w[i] ) aux = 0;
		}
		if( aux ){
			puts("YES");
			rep( i, 1, n+1 ) printf("%lld%s", ans[i], i == n ? "\n" : " " );
		}
		else puts("NO");
	}
}
