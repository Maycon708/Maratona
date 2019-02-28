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

typedef unsigned long long int ll;
typedef pair <ll, ll> ii;

ll pd[55][2][55];
int memo[55][2][55], cnt;
string s;

string C( ll n ){
	s.clear();
	while( n ){
		if(n&1) s.pb('1');
		else s.pb('0');
		n >>= 1;
	}
	reverse( all(s) );
	return s;
}

ll solve( int  p, int pref, int k ){
	if( p == s.size() ) return !k;
	ll &ans = pd[p][pref][k];
	if( memo[p][pref][k] != cnt ){
		memo[p][pref][k] = cnt;
		if( !k ) ans = solve( p+1, pref && s[p] == '0', 0 );
		else if( !pref ) ans = solve(p+1, 0, k) + solve( p+1, 0, k-1 );
		else if( s[p] == '0' ) ans = solve(p+1, 1, k);
		else ans = solve(p+1, 0, k) + solve(p+1, 1, k-1);
	}
	return ans;
}

const ll MAX = 1e19+10;

ll bb( ll v[], ll lim, int q, int n ){
	ll i = 0, j = (1LL<<n)-1;
	ll ans, aux, mid;	
	while( i < j ){
		mid = ( i+j+1 )/2, ans = 0, aux = 0;
		rep( k, 0, n ){ 
			if( mid&(1LL<<k) ){
				if( MAX >= ans && MAX-ans >= v[k] )
					ans += v[k];
				else
					aux = 1;
			}
		}
		if( ans > lim || aux ) j = mid-1;
		else i = mid;
	}
	cnt++;
	C(i);
	ll x = solve( 0, 1, q );
	return x;
}

int main(){
	int t, n, k;
	cin >> t;
	ll v[60], lo, hi;
	while(t--){
		scanf("%d%d", &n, &k );
		rep( i, 0, n ) scanf("%llu", &v[i] );
		scanf("%llu%llu", &lo, &hi );
		sort(v, v+n);
		ll ans = bb(v, hi, k, n ) - (lo ? bb(v, lo-1, k, n ) : bb(v, lo, k, n) );
		printf("%llu\n", ans );
	}
}
