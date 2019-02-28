#include<stdio.h>

int main(){
	
	long long n, m, v[111], i, j, k, dp[101][101], ans;
	
	while( scanf("%lld%lld", &n, &m ) != EOF && n ){
		for( i = 0; i <= n; ++i )
			for( j = 0; j <= m; ++j ) 
				dp[i][j] = 0;
		for( i = 0; i < n; ++i ) scanf("%lld", v+i ), dp[i][1] = 1;
		for( i = n-1; i >= 0; --i ){
			for( j = 1; j <= m; ++j ){
				for( k = i+1; k < n; ++k ){
					if( v[i] < v[k] ) dp[i][j] += dp[k][j-1];
				}
			}
		}
		ans = 0;
		for( i = 0; i < n; ++i ) ans += dp[i][m];
		printf("%lld\n", ans ); 
	}
	return 0;
}
