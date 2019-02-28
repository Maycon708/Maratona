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

#define N 1001
#define K 1001

int n, k;
ll F[N][K], P[N][K], sum[N], x[N], C[N];

inline ll cost( int i, int j ){
	return x[j] * ( C[j] - C[i-1] ) - ( sum[j] - sum[i-1] );
}

ll Knuth(){
	for( int i = 1; i <= k; i++ ){
		P[i][i] = max( i-1, 1 );
		F[i][i] = 0;
	}
	for( int i = 1; i <= n; i++ ) P[i][1] = 1, F[i][1] = cost( 1, i );
	for( int i = 2; i <= n; i++ ){
		for( int j = min( k, i-1 ); j > 1; j-- ){
			F[i][j] = INF;
			int aux = ( j == k )? i-1 : P[i][j+1];
			for( int k = P[i-1][j]; k <= aux; k++ ){
				ll w = F[k][j-1] + cost( k+1, i );
				if( F[i][j] > w ) F[i][j] = w, P[i][j] = k;
			}	
		}
	}
	return F[n][k];
}

int main(){
//	freopen( "A.in", "r", stdin );
	while( scanf("%d%d", &n, &k ) != EOF ){
		for( int i = 1; i <= n; i++ ){
			scanf("%lld%lld", &x[i], &C[i] ); 
			sum[i] = C[i] * x[i] +  sum[i-1];
			C[i] += C[i-1];
		}
		if( k >= n ){
			printf("0\n");
			continue;
		}
		printf("%lld\n", Knuth() );
	}
}

