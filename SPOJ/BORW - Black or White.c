#include<stdio.h>

int dp[250][250][250];

int max( int a, int b ){ return a > b ? a : b; }

int main(){

	int  n, v[250], i, j, k; 
	
	while( scanf("%d", &n ) != EOF && n != -1 ){
		v[0] = -1 << 30; 
		v[1] = +1 << 30;
		for( i = 0; i < n; ++i ) scanf("%d", v+i+2 );
		
		for( i = 0; i <= n+2; ++i )
			for( j = 0; j <= n+2; ++j )
				for( k = 0; k <= n+2; ++k )
					dp[i][j][k] = 0;
		
		for( i = n+1; i >= 0; --i ){
			for( j = 0; j < n+2; ++j ){
				for( k = 0; k < n+2; ++k ){
					dp[i][j][k] = dp[i+1][j][k];
					if( v[i] > v[j] ) dp[i][j][k] = max( dp[i][j][k], 1 + dp[i+1][i][k] );
					if( v[i] < v[k] ) dp[i][j][k] = max( dp[i][j][k], 1 + dp[i+1][j][i] ); 
				}
			}
		}
		printf("%d\n", n - dp[2][0][1] );
	}		
	
}
