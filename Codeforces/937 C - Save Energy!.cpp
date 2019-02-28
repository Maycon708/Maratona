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
typedef long double ld;

int main(){
	ll k, d, t;
	
	while( cin >> k >> d >> t ){
		ll ciclo = d * (( k+d-1 )/d );
		ll toff = ciclo - k;
		ld cook = ld(k)/ld(t) + toff/ld(2.0*t);
		ll need = ld(1)/cook;
		ld rest = t - need * cook * t;
		ld ans = rest;
		if( rest > k ){
			ans = k + ( rest-k ) * 2;
		}
		cout << fixed << setprecision(15) << need*ciclo + ans << endl;
	}
}
