#include <bits/stdc++.h>

#define INF 1LL << 62
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 1, l+1 ){ rep( j, 1, c+1 ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

#define N 5005
#define K 5005

int n, k;
ll F[N][K], S[2][N], best[N][N], A[N], B[N];
int P[N][K], h[N], x[N];

ll Knuth(){
	for( int i = 1; i <= k; i++ ){
		P[i][i] = max( i-1, 1 );
		F[i][i] = 0;
	}
	for( int i = 1; i <= n; i++ ) P[i][1] = 1, F[i][1] = best[1][i];
	for( int i = 2; i <= n; i++ ){
		for( int j = min( k, i-1 ); j > 1; j-- ){
			F[i][j] = INF;
			int aux = ( j == k )? i-1 : P[i][j+1];
			for( int k = P[i-1][j]; k <= aux; k++ ){
				ll w = F[k][j-1] + best[k+1][i];
				if( F[i][j] > w ) F[i][j] = w, P[i][j] = k;
			}	
		}
	}
	return F[n][k];
}

inline ll cut_cost(const int k, const int i, const int j) {
    if (i == j) return 0;
    return x[k] * ( (A[k] << 1) - A[i - 1] - A[j]) + B[j] + B[i - 1] - (B[k] << 1);
}

int main(){
//	freopen( "A.in", "r", stdin );
	while( scanf("%d%d", &n, &k ) != EOF ){
		for( int i = 1; i <= n; i++ ){
			scanf("%d%d", &x[i], &h[i] );
			A[i] = A[i-1] + h[i]; 
			B[i] = B[i-1] + ll(x[i]) * ll(h[i]); 
		}
		if( k >= n ){
			printf("0\n");
			continue;
		}
		for( int i = 1; i <= n; ++i )	best[i][i] = 0, S[1][i] = i;
	    for( int x = 2; x <= n; ++x )
	        for( int i = 1; i + x - 1 <= n; ++i ){
	            int bi = S[(x - 1) & 1][i], bx = S[(x - 1) & 1][i + 1];
	            for( int j = bi; j <= bx; ++j)
	                if( cut_cost( bi, i, i + x - 1) > cut_cost( j, i, i + x - 1 )) bi = j;
	            best[i][i + x - 1] = cut_cost(bi, i, i + x - 1);
	            S[x & 1][i] = bi;
	        }
		printf("%lld\n", Knuth() );
	}
}

