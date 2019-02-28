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

typedef pair <int, int> ii;
typedef long long int ll;

ll n, v[25], fim, ini;
ll sum[25];
vector < ll > w[25];
const ll mod = 1300031;

void MMC( int pos, ll mmc, int b){
	if( mmc > fim ) return;
	if( pos == n ){
		w[b].pb(mmc);
		return;
	}
	MMC( pos+1, mmc, b );
	ll aux =  mmc/ __gcd( v[pos], mmc ) * v[pos];
	MMC( pos+1, aux, b+1 );
}

ll F( ll u ){
	if( u > fim ) return 0;
	ll a = ( ( ini/u ) + ( ini%u != 0 ) ) * u;
	ll b = ( fim / u ) * u;
	ll term = ( b - a )/u + 1;
	ll soma = ( a + b ) * term /2;
	return soma;
}

void soma(){
	rep( b, 1, n+1 ){
		sum[b] = 0;
		rep( j, 0, w[b].size() ){
			sum[b] = (  sum[b] + F( w[b][j] ) );
			if( sum[b] > mod ) sum[b] %= mod;
		}
	}
}

int main(){
	
	ll t;
	scanf("%lld", &t );
	while( t-- ){
		scanf("%lld%lld%lld", &ini, &fim, &n );
		rep( i, 0, n ){
			scanf("%lld", &v[i] );
		}
		rep( i, 0, n+1 ) w[i].clear();
		MMC( 0, 1, 0 );
		soma();
		ll ans = 0;
		rep( i, 1, n+1 ){
			if( i&1 ) ans = ( ans + sum[i] );
			else ans = ( ans - sum[i] );
		}
		printf("%lld\n", ( ans%mod + mod )%mod );
	}
}


