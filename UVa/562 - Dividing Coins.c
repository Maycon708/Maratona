#include <stdio.h>
#include <stdlib.h>

int dp[110][50100], n, v[110];

int min( int a, int b ){ return a < b ? a : b; }

int main(){
	int t, i, j;
	scanf("%d", &t );
	while( t-- ){
		scanf("%d", &n );
		for( i = 0; i < n; ++i ) scanf("%d", v+i );
		for( i = 0; i < 50100; ++i ) dp[n][i] = i;
		for( i = n-1; i >= 0; --i )
			for( j = 50000; j >= 0; --j )
				dp[i][j] = min( dp[i+1][j+v[i]], dp[i+1][abs(j-v[i])] );	
		printf("%d\n", dp[0][0] );
	}	
}
