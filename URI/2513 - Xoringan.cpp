#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef unsigned long long int ll;

const ll mod = 1e9+7;
const ll mod2 = mod * mod;

#define gc getchar_unlocked

void scan( ll &x ){
    register int c = gc();
    x = 0;
    for( ; ( c < 48 || c > 57 ) && c != EOF; c = gc() );
    for( ; c > 47 && c < 58; c = gc() ){ x = (x << 1 ) + ( x << 3) + c - 48; }
}

inline ll _mod( ll u ){
	return u - ll( u/mod ) * mod;
}

int main(){
	ll n, v[1002], X[1002];
	while(42){
		scan(n);
		if( !n ) break;
		ll ans = 0;
		X[0] = 0;
		rep( i, 1, n+1 ) scan( v[i] ), X[i] = X[i-1]^v[i];
		rep( i, 1, n+1 ){
			rep( j, i, n+1 ){
				ll aux = ( X[j] ^ X[i-1] );
				if( aux >= mod2 ) aux = _mod(aux);
				ans += aux;
				if( ans >= mod2 ) ans -= mod2;
			}
		}
		printf("%llu\n", _mod(ans) );
	}

}

