#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

map<ll, ll> mp;

ll n;

bitset<1000000> p;
vector<ll> primes;
vector<ii> fatores;

void crivo(){
	p.set();
	p[0] = p[1] = 0;
	for( int i = 2; i < 1000000; i++ ){
		if( !p[i] ) continue;
		primes.pb(i);
		for( int j = i+i; j < 1000000; j += i ) p[j] = 0;
	}
}

ll C( ll n ){
	ll ans = 0;
	for( int i = 12; i >= 0; i-- ) ans = ( ans * 10 ) + (( n & 1 << i ) != 0 );
	return ans;
}

void divisores( int p, ll val, ll n ){
	if( p == fatores.size() ){
		if( !mp.count(val) ) mp[val] = n;
		return;
	}
	ll aux = 1;
	for( int i = 0; i <= fatores[p].S; i++ ){
		divisores(p+1, val*aux, n );
		aux *= fatores[p].F;
	}
}

void fatora( ll N ){
	ll n = N;
	fatores.clear();
	for( int i = 0; i < primes.size() && n > 1; i++ ){
		ll v = primes[i];
		if( n%v != 0 ) continue;
		int cont = 0;
		while( n%v == 0 ) cont++, n /= v;
		fatores.pb(ii(v, cont));		
	}
	if( n != 1 ) fatores.pb(ii(n, 1));
	divisores(0, 1, N);
}

void pre(){
	for( int i = 1; i < (1<<12); i++ ){
		ll v = C(i);
		fatora(v);
	}
}

int main(){
	crivo();
	pre();
	while( scanf("%lld", &n ) != EOF ){
		if( mp.count(n) ) printf("%lld\n", mp[n] );
		else puts("-1");
	}

}
