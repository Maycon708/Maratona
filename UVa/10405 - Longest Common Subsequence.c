#include<stdio.h>
#include<string.h>

int max( int a, int b ){ return a > b ? a : b; }

int dp[1001][1001];

int main(){

	char s1[1001], s2[1001];
	int t1, t2, i, j;
	while( gets(s1) ){
		gets(s2);
		t1 = strlen(s1);
		t2 = strlen(s2);
		for( i = 0; i < t1; i++ ) dp[i][t2] = 0;
		for( i = 0; i < t2; i++ ) dp[t1][i] = 0;
		dp[t1][t2] = 0;
		for( i = t1-1; i >= 0; i-- ){
			for( j = t2-1; j >=0; j-- ){
				dp[i][j] = max( dp[i+1][j], dp[i][j+1] );
				if( s1[i] == s2[j] ) dp[i][j] = max( dp[i][j], dp[i+1][j+1] + 1 );
			}
		}
		printf("%d\n", dp[0][0] );
	}
	
	return 0;
}
