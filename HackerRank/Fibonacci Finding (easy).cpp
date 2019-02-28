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
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef unsigned long long int ll;

const int MAXN = 5, mod = 1e9+7;

ll mat[MAXN][MAXN];
ll ans[MAXN][MAXN];
ll tmp[MAXN][MAXN];
ll M[MAXN][MAXN][MAXN];
ll N = 2;

void multiply(ll m1[][MAXN], ll m2[][MAXN]) {
	memset( tmp, 0, sizeof(tmp) );
	for( int a = 0; a <= N; ++a ){
    	for( int b = 0; b <= N; ++b ){
    		for( int c = 0; c <= N; ++c ){
    			tmp[a][b] += ( m1[a][c] * m2[c][b] )%mod;
    		}
    		tmp[a][b] = ( tmp[a][b] )%mod;
		}
	}
	memcpy( m1, tmp, sizeof tmp );
}    

int main(){

	ll n, k, l, p, A, B;
	int t;
	scanf("%d", &t );
	while( t-- ){
		scanf("%llu%llu%llu", &A, &B, &p );
		ans[0][0] = ans[1][1] = 1;
		mat[0][0] = 1, mat[0][1] = 1, mat[1][0] = 1;
		ans[0][1] = ans[1][0] = mat[1][1] = 0;
		p--; 
	    while( p ){
	    	if( p&1 ) multiply( ans, mat );
	    	p >>= 1;
			multiply( mat, mat );
	    }
        printf("%llu\n", ( (ans[0][0] * B )%mod+ (ans[0][1] * A )%mod )%mod );
	}

}
