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

double n[3], H[60][4][4][2], F[60][60], p[6];

double h( int m, int q, int a, int op ){
	double a1 = m/n[op], a2 = ( n[op] - m )/(n[op]);
	if( a > m || a > q ) return 0;
	if( !a ) return pow( a2, q );
	if( H[m][q][a][op] > -1 ) return H[m][q][a][op];
	return H[m][q][a][op] = a1 * h( m-1, q-1, a-1, op ) + a2 * h( m, q-1, a, op );
}

double g( int m1, int m2, int a, int b ){
	double ans = 0;
	for( int i = 0; i <= 2; i++ ) ans += ( p[i] * h( m1, i, a, 0 ) * h( m2, 3-i, b, 1 ) );
	return ans; 
}

double f( int m1, int m2 ){
	if( !m1 && !m2 ) return 0;
	if( F[m1][m2] > -1 ) return F[m1][m2];
	double ans = 1;
	for( int i = 0; i <= 3; i++ ){
		for( int j = 0; j <= 3; j++ ){
			if( i+j == 0 || i+j > 3 || i > m1 || j > m2 ) continue;
			ans += f( m1 - i, m2 - j ) * g( m1, m2, i, j );
		}
	}
	return F[m1][m2] = ans / ( 1.0 - g( m1, m2, 0, 0 ) );
}

int main(){
	int m1, m2;
	double w1, w2;
	while( scanf("%lf%lf", &n[0], &n[1] ) != EOF ){
		scanf("%d%d", &m1, &m2 );
		scanf("%lf%lf", &w1, &w2 );
		memset( H, -INF, sizeof H );
		memset( F, -INF, sizeof F );
		double p1 = w1/( w1+w2 ), p2 = 1 - p1, aux = 1 - p1 * p1 * p1;
		p[0] = p2 * p2 * p2 / aux;
		p[1] = 3 * p1 * p2 * p2 / aux;
		p[2] = 3 * p1 * p1 * p2 / aux;
		printf("%.3f\n", f( m1, m2 ) );
	}
}

