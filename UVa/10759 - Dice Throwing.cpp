#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define it(i, a)  for( typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef unsigned long long int ll;

ll k, n, pd[25][160];
bool memo[25][160];

ll solve( int pos, int t ){
	if( pos == n ) return t >= k;
	if( memo[pos][t] ) return pd[pos][t];
	memo[pos][t] = 1;
	
	pd[pos][t] = 0;
	rep( i, 1, 7 ){
		pd[pos][t] += solve( pos+1, t+i ); 
	}
	return pd[pos][t];
}

ll eleva( ll b, ll e ){
	ll ans = 1;
	while( e ){
		if( e&1 ) ans *= b;
		b *= b;
		e >>= 1;
	}
	return ans;
}

ll gcd( ll a, ll b ){
	while( a ){
		ll c = b%a;
		b = a;
		a = c;
	}
	return b;
}

int main(){
	while( cin >> n >> k ){
		if( !n && !k ) break;
		
		memset( memo, 0, sizeof memo );
		ll a = solve( 0, 0 );
		if( !a ){
			printf("0\n");
			continue;
		}
		ll b = eleva( 6, n );
		ll c = gcd( a, b );
		a /= c, b /= c;
		if( b == 1 ) printf("%llu\n", a );
		else printf("%llu/%llu\n", a, b );
	}
}

