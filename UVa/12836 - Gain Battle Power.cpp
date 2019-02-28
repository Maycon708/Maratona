#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i+1][j+1] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

#define N 1010

int sum[N], v[N], P[N][N], F[N][N], n;

void LIS(){
	int L[N], R[N];
	
	for( int i = 1; i <= n; i++ ) R[i] = 0, L[i] = 1;
	
	for( int i = n; i > 0; i-- ){
		for( int j = i+1; j <= n; j++ )
			if( v[i] > v[j] ) L[i] = max( L[i], L[j] + 1 );
	}
	
	for( int i = 1; i <= n; i++ ){
		for( int j = i-1; j > 0; j-- )
			if( v[i] > v[j] ) R[i] = max( R[i], R[j] + 1 );
	}
	for( int i = 1; i <= n; i++ ) sum[i] = sum[i-1] + R[i] + L[i];
}

int Knuth(){
	for( int i = 1; i <= n; i++ ){
		for( int j = 1; j <= n; j++ ) F[i][j] = INF * ( i < j );
		P[i][i] = i;	
	}
	for( int l = 2; l <= n; l++ ){
		for( int i = 1; i <= n - l + 1; i++ ){
			int j = i + l -1;
			for( int k = P[i][j-1]; k <= P[i+1][j]; k++ ){
				int w = ( sum[j] - sum[i-1] ) + F[i][k-1] + F[k][j];
				if( w < F[i][j] ) F[i][j] = w, P[i][j] = k; 
			}
		}
	}
	return F[1][n];
}

int main(){
	int t, test = 1;
	scanf("%d", &t );
	while( t-- ){
		scanf("%d", &n );
		for( int i = 1; i <= n; i++ ) scanf("%d", &v[i] );
		LIS();
		printf("Case %d: %d\n", test++, Knuth() );
	}
}
 
