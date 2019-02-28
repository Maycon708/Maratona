#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

#define INF 0x3f3f3f3f
#define N 501

#define gc getchar_unlocked

void scan( int &x ){
    register int c = gc();
    x = 0;
    for( ; ( c < 48 || c > 57 ) && c != EOF; c = gc() );
    for( ; c > 47 && c < 58; c = gc() ){ x = (x << 1 ) + ( x << 3) + c - 48; }
}

void D( int m[N][N], int n ){
	for( int i = 1; i <= n; i++ ){
		for( int j = 1; j <= n; j++ ){
			printf("%d ", m[i][j] );
		}
		printf("\n");
	}
}

int main(){
	int n, p, x, y, B, W, b[N][N], w[N][N], i, j;
	while( 42 ){
		scan(n); scan(p);
		if( !n ) break;
		
		for( i = n; i > 0; i-- )
			for( j = n; j > 0; j-- )
				b[i][j] = w[i][j] = 1;		
		for( i = n; i > 0; i-- ) b[i][n] = b[n][i] = w[i][n] = w[n][i] = 1;
		
		for( i = p; i > 0; i-- ){
			scan(x), scan(y);
			b[x][y] = 0;
		}
		for( i = p; i > 0; i-- ){
			scan(x), scan(y);
			w[x][y] = 0;
		}
		for( i = n-1; i > 0; i-- ){
			for( j = n-1; j > 0; j-- ){
				if( b[i][j] ) b[i][j] = min( b[i+1][j+1], min( b[i+1][j], b[i][j+1] ) ) + 1;
				if( w[i][j] ) w[i][j] = min( w[i+1][j+1], min( w[i+1][j], w[i][j+1] ) ) + 1;
			}
		}
//		D( w, n );
//		printf("------\n");
//		D( b, n );
		B = 0, W = 0;
		for( i = n; i > 0; i-- ){
			for( j = n; j > 0; j-- ){
				B += max( 0, w[i][j] - b[i][j] );
				W += max( 0, b[i][j] - w[i][j] );
			}
		}
		printf("%d %d\n", B, W );
	}
}

