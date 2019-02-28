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
typedef long long int ll;

ll eleva( ll b, ll e, ll mod ){
	ll ans = 1;
	while( e ){
		if( e&1 ) ans = (ans*b)%mod;
		b = (b*b)%mod;
		e >>= 1;
	}
	return ans;
}

int main(){
	
	ll n;
	while( scanf("%lld", &n ) != EOF ){
		int cnt = 0;
		for( int i = n; i; i/= 10 ) cnt++;
		ll mod = eleva( 10, cnt, 1LL<<63 );
		ll k = eleva( n, n, mod );
		if( k == n ) puts("SIM");
		else puts("NAO");
	}
	
}
