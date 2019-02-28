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

const int MAX = 5e5+10;

ll bit[MAX];

void update( int x, ll v ){
	for( int i = x; i < MAX; i += i&-i ) bit[i] = max( bit[i], v );  
}

ll query( int x ){
	ll ans = 0;
	for( int i = x; i > 0; i -= i&-i ) ans = max( ans, bit[i] );
	return ans;
}

int main(){
	ll n, b, f, d;
	while( scanf("%lld", &n ) != EOF ){
		memset( bit, 0, sizeof bit );
		map<ii, ll> mp;
		map<ll, ll> mp2;
		rep( i, 0, n ){
			scanf("%lld%lld%lld", &b, &f, &d );
			mp[ii(b,-f)] += d;
		}
		ll ans = 0, cnt = 1;
		for( auto x : mp  ) mp2[-x.F.S] = 1;
		for( map<ll, ll> :: iterator it = mp2.begin(); it != mp2.end(); it++ ) it -> S = cnt++; 
		for( auto x : mp  ){
			int p = mp2[-x.F.S];
			ll v = x.S;
			ll aa = query(p-1) + v;
			ans = max( ans, aa );
			update( p, aa );
		}
		printf("%lld\n", ans );
	}
}
