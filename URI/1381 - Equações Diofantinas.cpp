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
typedef long long int ll;

const int mod = 1300031;
ll fat[2000100];

ll inv( ll n ){
	ll ans = 1;
	int e = mod - 2;
	while( e ){
		if( e&1 ) ans = ( ans * n )%mod;
		n = ( n * n )%mod;
		e >>= 1;
	}
	return ans;
}

#define gc getchar_unlocked

void scanint( int &x ){
    register int c = gc();
    x = 0;
    for( ; ( c < 48 || c > 57 ); c = gc() );
    for( ; c > 47 && c < 58; c = gc() ){ x = (x << 1 ) + ( x << 3) + c - 48; }
}


int main(){
	
	fat[0] = 1;
	rep( i, 1, 2000100 ){
		fat[i] = ( fat[i-1] * i );
		if( fat[i] >= mod ) fat[i] %= mod;
	}
	
	int n, k, t;
	scanint(t);
	while( t-- ){
		scanint(n), scanint(k);
		printf("%lld\n", ( fat[n+k-1] * inv( ( fat[n-1] * fat[k] )%mod ) )%mod );
	}
}

