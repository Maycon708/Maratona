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

ll pd[18][1<<18], bonus[18][18], v[18], n;

ll solve( int i, int m, int mask ){
	if( !m ) return 0;
	ll &ans = pd[i][mask];
	if( ans == -1 ){
		ans = 0;
		for( int j = 0; j < n; j++ ){
			if( mask & 1<<j ) continue;
			ans = max( ans, solve( j, m-1, mask|1<<j) + v[j] + bonus[i][j] );
		}
	}
	return ans;
}

int main(){
	
	ll m, k, a, b, c;
	while( scanf("%lld%lld%lld", &n, &m, &k ) != EOF ){
		rep( i, 0, n ){
			scanf("%lld", &v[i] );
			memset( bonus[i], 0, sizeof bonus[i] );
		}
		while( k-- ){
			scanf("%lld%lld%lld", &a, &b, &c );
			--a, --b;
			bonus[a][b] = c;
		}
		ll ans = 0;
		memset( pd, -1, sizeof pd );
		rep( i, 0, n ){
			ans = max( ans, v[i]+solve(i, m-1, 1<<i ) );
		}
		printf("%lld\n", ans );
	}
	
}
