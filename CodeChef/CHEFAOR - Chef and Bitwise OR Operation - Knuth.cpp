#include <bits/stdc++.h>

#define INF 1LL << 62
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 1, l+1 ){ rep( j, 1, c+1 ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

#define N 5050
#define K 5050

int n, k;
ll F[N][K], sum[N];
int P[N][K], g[N][N];

ll Knuth(){
	for( int i = 1; i <= k; i++ ){
		P[i][i] = max( i-1, 1 );
		F[i][i] = sum[i];
	}
	for( int i = 1; i <= n; i++ ) P[i][1] = 1, F[i][1] = g[1][i];
	for( int i = 2; i <= n; i++ ){
		for( int j = min( k, i-1 ); j > 1; j-- ){
			F[i][j] = 0;
			int aux = ( j == k )? i-1 : P[i][j+1];
			for( int k = P[i-1][j]; k <= aux; k++ ){
				ll w = F[k][j-1] + g[k+1][i];
				if( F[i][j] < w ) F[i][j] = w, P[i][j] = k;
			}	
		}
	}
	return F[n][k];
}

int main(){
	int t;
	scanf("%d", &t );
	while( t-- ){
		scanf("%d%d", &n, &k );
		for( int i = 1; i <= n; i++ ) scanf("%d", &g[i][i] ), sum[i] = g[i][i] + sum[i-1];
		for( int i = 1; i <= n; i++ ) for( int j = i+1; j <= n; j++ ) g[i][j] = g[i][j-1] | g[j][j];
		printf("%lld\n", Knuth() );
	}
}

