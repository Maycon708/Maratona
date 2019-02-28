#include<stdio.h>

long long max( long long a, long long b ){ return a > b ? a : b; }

long long dp[1010][2010];

int main(){
	
	long long n, cap, c[1010], v[1010], i, j;
	
	while( scanf("%lld%lld", &n, &cap ) != EOF ){
		 for( i = 0; i < n; i++ ) scanf("%lld%lld", c+i, v+i );
		 for( i = 0; i <= cap; i++ ) dp[n][i] = 0;
		 for( i = 0; i <= n; i++ ) dp[i][cap] = 0;
		 for( i = n-1; i >= 0; i-- ){
		 	for( j = cap; j >= 0; j-- ){
		 		dp[i][j] = dp[i+1][j];
		 		if( j + c[i] <= cap ) dp[i][j] = max( dp[i][j], dp[i][j+c[i]] + v[i] );
		 	}
		 }
		 printf("%lld\n", dp[0][0] );
	}
	
	return 0;
}
