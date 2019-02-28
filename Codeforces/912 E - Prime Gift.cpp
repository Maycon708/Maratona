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
#define N 25000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

const ll MAX = 1e18;

void build( vector<ll> &a, ll *v, int n, int i ){
	a.pb(1);
	for( ; i < n; i += 2 ){
		rep( j, 0, a.size() ){
			if( a[j] <= MAX/v[i] ) a.pb(a[j]*v[i]);
		}
	}
	sort(all(a));
}

ll count( vector<ll> &a, vector<ll> &b, ll v ){
	ll ans = 0, i, j = 0;
	for( i = a.size()-1; i >= 0; i-- ){
		for( ; j < b.size() && a[i] <= v/b[j]; j++ );
		ans += j;
	}
	return ans;
}

int main(){
	ll n, v[20], q;
	while( scanf("%lld", &n ) != EOF ){
		rep( i, 0, n ) scanf("%lld", &v[i] );
		scanf("%lld", &q );
		sort( v, v+n );
		vector<ll> a, b;
		build( a, v, n, 0 );
		build( b, v, n, 1 );
		ll lo, hi, mid;
		lo = 0, hi = MAX;
		while( lo < hi ){
			mid = lo+(hi-lo)/2;
			ll aux = count( a, b, mid );
			if( aux >= q ) hi = mid;
			else lo = mid+1;
		}
		cout << hi << endl;
	}
}
