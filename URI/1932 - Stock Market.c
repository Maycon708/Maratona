#include<stdio.h>

long long max( long long a, long long b ){ return a > b ? a : b; }

int main(){
	
	long long c, n, v[200100], dp[200100][2], i;
	
	while( scanf("%lld%lld", &n, &c ) != EOF ){
		for( i = 0; i < n; ++i ) scanf("%lld", v+i );
		dp[n][0] = dp[n][1] = 0;
		for( i = n-1; i >= 0; i-- ){
			dp[i][0] = max( dp[i+1][0], dp[i+1][1] - v[i] - c );
			dp[i][1] = max( dp[i+1][1], dp[i+1][0] + v[i] );
		}
		printf("%lld\n", dp[0][0] );		
	}
	return 0;
}
