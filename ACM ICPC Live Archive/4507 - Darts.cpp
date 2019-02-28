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

double pd[600][600];

int C( int i ){
	return ( i + 20 ) % 20;
}

int v[] = { 20, 1, 18, 4, 13, 6, 10, 15, 2, 17, 3, 19, 7, 16, 8, 11, 14, 9, 12, 5 };

double solve( int n, int m ){
	if( !n ) return 1;
	if( !m ) return 0;
	if( pd[n][m] > -1 ) return pd[n][m];
	double ans = 0;
	rep( i, 0, 20 ){
		double p = 0, cnt = 0;
		rep( j, 0, 20 ){
			rep( k, -1, 2 ){
				if( v[C(i+k)] > n && v[j] > m ) cnt++; 
				else p += ( 1.0/60.0 * solve(( v[C(i+k)] <= n )? n - v[C(i+k)] : n,( v[j] <= m )? m-v[j] : m ) );
			}
		}
		p = ( p * 60.0 )/( 60.0 - cnt );
		ans = max( ans, p );
	}
	
	
	return pd[n][m] = ans;
}

int main(){
	int n;
	memset( pd, -INF, sizeof pd );
	solve( 500, 500 );
	while( scanf("%d", &n ) != EOF && n ){
		double a = 0, cnt = 0;
		rep( i, 0, 20 ){
			if( n >= v[i] ) a += ((1.0/20.0) * ( 1.0 - solve(n, n-v[i]) ));
			else a += ((1.0/20.0) * ( 1.0 - solve(n, n) ));
		}
		printf("%.12f %.12f\n", a, solve(n,n) );
	}	
}
