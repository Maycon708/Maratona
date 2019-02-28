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

bitset<1000100> primes;

void crivo(){
	primes.set();
	primes[0] = primes[1] = 0;
	for( int i = 2; i < 1000100; i++ ){
		if( !primes[i] ) continue;
		for( int j = i+i; j < 1000100; j += i ) primes[j] = 0;
	}
}

int main(){
	ll n, u;
	crivo();
	while( scanf("%I64d", &n ) != EOF ){
		while( n-- ){
			scanf("%I64d", &u );
			ll w = sqrt(u);
			if( w*w == u && primes[w] ) puts("YES");
			else puts("NO");
		}
	}
}
