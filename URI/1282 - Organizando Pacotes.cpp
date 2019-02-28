#include <bits/stdc++.h>

#define INF 1LL << 60
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define S second
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

#define N 1010

ll cost[N][N];
ll F[N][N];
ll P[N][N];

void fill( int k, int i, int j, int a, int b ){
	if( i > j ) return;
	int mid = ( i + j ) >> 1;
	P[k][mid] = -1;
	F[k][mid] = INF;
	rep( id, a, b+1 ){
		ll aux = F[k-1][id] + cost[id+1][mid];
		if( aux < F[k][mid] ){
			F[k][mid] = aux;
			P[k][mid] = id;
		}
	}
	fill( k, i, mid-1, a, P[k][mid] );
	fill( k, mid+1, j, P[k][mid], b );
}

int main(){
	ll n, k, x[N], w[N];
	while( scanf("%lld%lld", &n, &k ) != EOF ){
		rep( i, 0, n ){
			scanf("%lld%lld", &x[i], &w[i] );
		}
		for( int i = n-1; i >= 0; i-- ){
			cost[i][i] = 0;
			rep( j, i+1, n ){
				cost[i][j] = ( w[i] * ( x[j] - x[i] ) );
				if( i+1 != n ) cost[i][j] += cost[i+1][j];
			}
		}
		rep( i, 0, n ){
			F[1][i] = cost[0][i];
			P[1][i] = 0;
		}
		rep( i, 2, k+1 ){
			fill( i, 0, n-1, 0, n-1 );
		}
		printf("%lld\n", F[k][n-1] );
	}
}

