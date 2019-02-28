#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-2
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef double ll;

ll mat[MAXN][MAXN];
ll ans[MAXN][MAXN];
ll tmp[MAXN][MAXN];
int N = 3;

void multiply(ll m1[][MAXN], ll m2[][MAXN]) {
	memset( tmp, 0, sizeof(tmp) );
	for( int a = 0; a <= N; ++a ){
    	for( int b = 0; b <= N; ++b ){
    		for( int c = 0; c <= N; ++c ){
    			tmp[a][b] += ( m1[a][c] * m2[c][b] );
    		}
    		tmp[a][b] = ( tmp[a][b] );
		}
	}
	memcpy( m1, tmp, sizeof tmp );
}

double G2R( double g ){
	return ( g * M_PI )/180;
}

int main(){

	int t, p;
	ll a, l;
	scanf("%d", &t );
	while( t-- ){
		scanf("%lf%lf%d", &a, &l, &p );
		rep( i, 0, 3 ){
			rep( j, 0, 3 ) 
				ans[i][j] = mat[i][j] = 0;
			ans[i][i] = 1;
		}
		a = G2R(a);

		mat[0][0] = cos(a), mat[0][1] = -sin(a), mat[0][2] = 1;
		mat[1][0] = sin(a), mat[1][1] =  cos(a);
		mat[2][2] = 1;	
		
		while( p ){
	    	if( p&1 ) multiply( ans, mat );
	    	p >>= 1;
			multiply( mat, mat );
	    }	
		double a = ans[0][2] * l, b = ans[1][2] * l;
		if( fabs( a ) < EPS ) a = 0;
		if( fabs( b ) < EPS ) b = 0;
		printf("%.2f %.2f\n", a, b );
	}
}

