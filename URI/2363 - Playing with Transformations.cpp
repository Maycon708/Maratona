#include <bits/stdc++.h>

#define INF 30
#define rep(i, a, b) for(ll i = ll(a); i < ll(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
typedef pair <ll, ll>  ii;

const ll mod = 1e9 + 7;

ll solve( ll a, llu aux, ll k, ll m ){
//	debug2(k, m )
	if( m == 1 ) return (a%mod * 2)%mod;
	ll ans = 0, mid = m >> 1, aa = a + aux/2;
	if( k <= mid ){
		ans = solve(aa, aux * 2, k, mid);
	}
	else{
		ll f = ( (aa%mod) + ((mid-1+mod)%mod)*(aux%mod) )%mod;
		ll sum = (( (aa%mod) + (f%mod) ) * (mid%mod) )%mod;
		ans = solve(a, aux * 2, k-mid, mid + (m&1) ) + sum;
	}
	return ans%mod;
}

ll eleva( ll b, ll e ){
	ll ans = 1;
	while(e){
		if(e&1) ans = (ans*b)%mod;
		b = (b*b)%mod;
		e >>= 1;
	}
	return ans;
}

int main(){
	ll a, b, c;
	while( scanf("%lld%lld%lld", &a, &b, &c ) != EOF ){
		ll aa = (b-1) ? solve(1, 2, b-1, a) : 0;
		ll bb = solve(1, 2, c, a);
		ll ans = (( bb - aa + mod )%mod * eleva(2, mod-2) )%mod;
		printf("%lld\n", ans );
	}
}
