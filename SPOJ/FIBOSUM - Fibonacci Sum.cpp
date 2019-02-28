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

#define mod 1000000007

void multiply( ll a[2][2], ll b[2][2] ){
	ll c[2][2];
	memset( c, 0, sizeof c );
	rep( k, 0, 2 )
		rep( i, 0, 2 )
			rep( j, 0, 2 )
				c[i][j] = ( c[i][j] + ( a[i][k] * b[k][j] )%mod )%mod;
	memcpy( a, c, sizeof c );	
}

ll fib( ll n ){
	n--;
	ll mat[2][2] = { { 1, 1 }, { 1, 0 } };
	ll ans[2][2] = { { 1, 0 }, { 0, 1 } };
	
	while(n){
		if( n&1 ) multiply( ans, mat );
		multiply( mat, mat );
		n >>= 1;
	}
	return ans[0][0];
}

int main(){
	ll a, b, t;
	scanf("%lld", &t );
	while( t-- ){
		scanf("%lld%lld", &a, &b );
		printf("%lld\n", ( fib(b+2) - fib(a+1) + mod )%mod );
	}
}

