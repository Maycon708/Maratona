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

const int N = 1000100;

int v[N];
vector<int> primes;

void crivo(){
	memset( v, 1, sizeof v );
	v[0] = v[1] = 0;
	for( int i = 2; i < N; i++ ){
		if( !v[i] ) continue;
		for( int j = i+i; j < N; j += i ) v[j] = 0;
		primes.pb(i);
	}
}

int check( ll a ){
	if( a != 2 && !(a&1) ) return 0;
	ll limite = sqrt(a);
	rep( i, 0, primes.size() ){
		if( primes[i] > limite ) break;
		if( a%primes[i] == 0 ) return 0;
	}
	return 1;
}

int main(){
	ll n;
	crivo();
	while( scanf("%lld", &n ) != EOF ){
		if( !check(n) ){
			if( n&1 && !check( n-2 ) ) n--;
			n--;
		}
		printf("%lld\n", n-1 );
	}
}

