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
#define N 250
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;

int n;

void matMul( double a[5][5], double b[5][5] ){
	double c[5][5];
	rep( i, 0, n ) rep( j, 0, n ) c[i][j] = 0;
	rep( i, 0, n )
		rep( j, 0, n )
			rep( k, 0, n )
				c[i][j] += ( a[i][k] * b[k][j] );
	memcpy( a, c, sizeof c );			
}

void fastExp( double b[5][5], int k  ){
	double ans[5][5];
	rep( i, 0, n ) rep( j, 0, n ) ans[i][j] = (i == j);
	while( k ){
		if( k&1 ) matMul( ans, b );
		matMul( b, b );
		k >>= 1;
	}
	memcpy( b, ans, sizeof ans );
}

int main(){
	int q, u, v, k;
	double mat[5][5], aux[5][5];
	while( scanf("%d", &n ) != EOF ){
		rep( i, 0, n ) rep( j, 0, n ) scanf("%lf", &mat[i][j] );
		scanf("%d", &q );
		while( q-- ){
			scanf("%d%d%d", &u, &v, &k );
			memcpy( aux, mat, sizeof mat );
			
			fastExp(aux, k);
			printf("%.6f\n", aux[v-1][u-1] );
		}
	}	
}