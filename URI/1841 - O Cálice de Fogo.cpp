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

const int mod = 1e9+7;

ll _crivo_size = 1e7;
bitset < 10000010 > bs;
vector <int> primes;
ll v[1000000];

void crivo(){
	bs.set();
	bs[0] = bs[1] = 0;	
	for( ll i = 2; i <= _crivo_size; i++)
		if( bs[i] ){
			for( ll j = i*i; j <= _crivo_size; j += i ) bs[j] = 0;
			primes.pb( (int) i );
		}
}

void fatore( ll n ){
	rep( i, 0, primes.size() ){
		while( n% primes[i] == 0 ){
			v[i]++;
			n /= primes[i];
		}
	}
}

ll seg[4000000];

void build( int no, int i, int j ){
	if( i == j ){
		seg[no] = ( v[i] + 1 );
		return;
	}
	int left = no << 1, right = left ^ 1;
	int mid = ( i + j ) >> 1;
	build( left, i, mid );
	build( right, mid+1, j );
	seg[no] = ( seg[left] * seg[right] )%mod;
}

void update( int no, int i, int j, int p ){
	
	if( i > p || j < p ) return;
	
	if( i == j && i == p ){
		seg[no] = ( v[i] + 1 );
		return;
	}
	
	int left = no << 1, right = left ^ 1;
	int mid = ( i + j ) >> 1;
	update( left, i, mid, p );
	update( right, mid+1, j, p );
	seg[no] = ( seg[left] * seg[right] )%mod;
}

ll query( int no, int i, int j, int p ){
	
	if( i > p ) return 1;
	if( j <= p ) return seg[no];
	
	int left = no << 1, right = left ^ 1;
	int mid = ( i + j ) >> 1;
	ll a = query( left, i, mid, p );
	ll b = query( right, mid+1, j, p );
	return ( a * b )%mod;
}

int main(){
	ll n, a;
	
	crivo();
	int sz = primes.size();
	
	scanf("%lld", &n );
	
	fatore(n);
	build( 1, 0, sz );
	
	while( scanf("%lld", &a ) != EOF ){
		int pos = lower_bound( all(primes), a ) - primes.begin();
		v[pos]++;
		update( 1, 0, sz, pos );
		printf("%lld\n", query( 1, 0, sz, pos-1 ) );
	}
}

