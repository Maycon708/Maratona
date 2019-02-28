#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){
	int mat[101][101], n, a, i, j, resp;
	while( scanf("%d", &n ) != EOF ){
		for( i = 0; i <= n; i++ ){
			for( j = 0; j <= n; j++ ){
				scanf("%d", &mat[i][j] );
			}
		}
		for( i = 0; i < n; i++ ){
			for( j = 0; j < n; j++ ){
				a = mat[i][j] + mat[i][j+1] + mat[i+1][j] + mat[i+1][j+1];
				if( a > 1 ) printf("S");
				else printf("U");
			}
			printf("\n");
		}
	}
}
