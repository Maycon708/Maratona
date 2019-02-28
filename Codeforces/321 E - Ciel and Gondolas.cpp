#include <bits/stdc++.h>

#define INF 1LL << 60
#define rep(i, a, b) for(int i = int(a); i <= int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 1, l ){ rep( j, 1, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define S second
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;
#define N 4004
#define K 808

ll sum[N][N];
ll F[K][N];
ll P[K][N];

ll cost( int i, int j ){
	if( i > j ) return 0;
	return ( sum[j][j] - sum[i-1][j] - sum[j][i-1] + sum[i-1][i-1] ) >> 1;
}

#define gc getchar//_unlocked

void scan( ll &x ){
    register int c = gc(), aux = 0;
    x = 0;
    for( ; ( c < 48 || c > 57 ) && c != EOF; c = gc() ) if( c == '-' ) aux = 1;
    for( ; c > 47 && c < 58; c = gc() ){ x = (x << 1 ) + ( x << 3) + c - 48; }
    if( aux ) x *= -1;
}


void fill( int g, int i, int j, int a, int b ){
	if( i > j ) return;
	int mid = ( i + j ) >> 1;
	P[g][mid] = -1;
	F[g][mid] = INF;
	rep( k, a, b ){
		int new_cost = F[g-1][k] + cost( k+1, mid );
		if( new_cost < F[g][mid] ){
			F[g][mid] = new_cost;
			P[g][mid] = k;
		}
	}
	fill( g, i, mid-1, a, P[g][mid] );
	fill( g, mid+1, j, P[g][mid], b );
	
}

int main(){
	int n, k;
	while( scanf("%d%d", &n, &k ) != EOF ){
		rep( i, 1, n ){
			rep( j, 1, n ){
				scan( sum[i][j] );
				if( i ) sum[i][j] += sum[i-1][j];
				if( j ) sum[i][j] += sum[i][j-1];
				if( i && j ) sum[i][j] -= sum[i-1][j-1];
			}
		}
		rep( i, 1, n ){
			F[1][i] = cost( 1, i );
			P[1][i] = 0;
		}
		rep( i, 2, k ){
			fill( i, 1, n, 1, n );
		}
		printf("%lld\n", F[k][n] );
	}
}

