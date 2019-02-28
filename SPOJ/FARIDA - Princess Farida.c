#include<stdio.h>

long long max( long long a, long long b ){ return a > b ? a : b; }

int main(){
	
	long long casos, n, v[10100], dp[10100], teste, i;
	
	scanf("%lld", &casos );
	for( teste = 1; teste <= casos; ++teste ){
	
		scanf("%lld", &n );
		for( i = 0; i < n; ++i ) scanf("%lld", v+i ), dp[i] = 0;
		dp[n-1] = v[n-1];
		dp[n-2] = max( v[n-1], v[n-2] );
		for( i = n-3; i >= 0; i-- ) dp[i] = max( v[i] + dp[i+2], dp[i+1] );
		printf("Case %lld: %lld\n", teste, dp[0] );		
	}
	return 0;
}
