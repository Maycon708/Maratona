#include <bits/stdc++.h>
 
#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugP(a) cout << "F" << " = " << a.first << " --- " << "S" << " = " << a.second << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define EPS 1e-9
#define mp make_pair
 
using namespace std;
 
typedef pair <int, int> ii;
typedef long long int ll;

const ll mod = 1e8;

ll tmp[2][2];

const ll modulo( ll a ){
	return ( mod + a%mod )%mod;
}

void multiply(ll m1[2][2],ll m2[2][2]) {
	memset( tmp, 0, sizeof(tmp) );
	for( int a = 0; a < 2; ++a ){
    	for( int b = 0; b < 2; ++b ){
    		for( int c = 0; c < 2; ++c ){
    			tmp[a][b] += modulo( m1[a][c] * m2[c][b] );
    		}
    		modulo( tmp[a][b] );
		}
	}
	memcpy( m1, tmp, sizeof tmp );
}    

int main(){
 
	
	ll a, b, n, k;
	char s[10];
		     
    while( scanf("%lld%lld%lld%lld", &a, &b, &n, &k ) != EOF ){
		
		ll mat[2][2] = { { modulo(2LL*a), modulo(b-a*a) }, { 1, 0 } };
		ll ans[2][2] = { { 1, 0 }, { 0, 1 } };
		int e = n;
		while( e ){
	    	if( e&1 ) multiply( ans, mat );
			multiply( mat, mat );
	    	e >>= 1;
	    }
		ll z = modulo(ans[1][0]*2*a + ans[1][1]*2);
		if( a*a != b && ( n%2 == 0 || a*a > b ) ){
			z = modulo(z-1);
		}
		sprintf( s, "%04d", z );
		printf("%c\n", s[strlen(s)-k] );
    }   
     
    return 0;
}

