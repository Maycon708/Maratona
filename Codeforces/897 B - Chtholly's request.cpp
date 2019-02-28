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

ll C( ll a, ll mod ){
	ll ans = a, aux = 0;
	while( a ){
		ans *= 10;
		aux *= 10;
		aux += a%10;
		a /= 10;
		if( ans > 1e15 ) ans%=mod;
		if( aux > 1e15 ) aux%=mod;
	}
	return (ans + aux)%mod;
}

int main(){
	ll k, m, ans;
	while( scanf("%lld%lld", &k, &m ) != EOF ){
		ans = 0;
		rep( i, 1, k+1 ){
			ans += C(i, m);
			if( ans > 1e15 ) ans %= m;
		}
		printf("%lld\n", ans%m );
	}
}
