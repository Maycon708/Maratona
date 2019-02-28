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

const int mod = 1e9+7;

void multiply( ll A[3][3], ll B[3][3] ){
	ll C[3][3] = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }};
	rep( k, 0, 3 ){
		rep( i, 0, 3 ){
			rep( j, 0, 3 ){
				C[i][j] = ( C[i][j] + A[i][k] * B[k][j] )%mod;
			}
		}
	}
	memcpy( A, C, sizeof C );
}

int main(){
	
	ll n;
	while( scanf("%lld", &n ) != EOF ){
		ll mat[3][3] = { { 0, 1, 1 }, { 1, 0, 0 }, { 0, 1, 0 } };
		ll ans[3][3] = { { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 } };
		
		if( n == 1 ) printf("1\n");
		else if( n == 2 ) printf("2\n");
		else{
			n -= 3;
			while( n ){
				if( n&1 ){
					multiply(ans, mat);
				}
				multiply(mat, mat);
				n >>= 1 ;
			}
			printf("%lld\n", ( ans[0][0] * 2 + ans[0][1] * 2 + ans[0][2] * 1 )%mod );
		}
	}
}
